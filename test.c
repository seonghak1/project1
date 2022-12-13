#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

char inputdata[10000][500]; // ���� txt ���� ������ ���� 2�����迭

float Ax[10000]; // ���ӵ� x,y,z
float Ay[10000];
float Az[10000];

float Gx[10000]; // ���ӵ� x,y,z
float Gy[10000];
float Gz[10000];

float Mx[10000]; // ���ڱ� x,y,z
float My[10000];
float Mz[10000];

char cAx[10000][10];
char cAy[10000][10];
char cAz[10000][10];

char cGx[10000][10];
char cGy[10000][10];
char cGz[10000][10];

char cMx[10000][10];
char cMy[10000][10];
char cMz[10000][10];

int len = 0;
int count = 0;
int state = 0;


int main(void) {

	// ���� ������ �����Ͽ� �ش� �����̸��� �ֱ�

	FILE* fp = fopen("left_right_up_down.txt", "r");

	// ������ txt ������ ������ ���� �Ŀ� inputdata���� �����ϴ� ���

	for (int i = 0; i < 10000; i++) {
		fgets(inputdata[i], 500, fp);
		if (inputdata[i][0] == 0)
		{
			len = i;
			break;
		}
	}

	fclose(fp);


	int comma = 0; // boash ���α׷��� ���� ���� �����ʹ� ���������� �迭�Ǿ� �ֱ⿡ comma�� ���� �з������ϴ�

	int start = 0; // �迭�� ������ �ʱ�ȭ�� �Ѵ�.

	for (int i = 0; i < len; i++)
	{
		
		// comma�� ���� �з��Ǿ��� ���� string ���·� ���ӵ�, ���ڱ�, ���̷ΰ��� ��Ƴ���

		for (int j = 0; j < 500; j++)
		{
			if (inputdata[i][j] == ',')
			{
				comma++;
				start=0;
				continue;

			}// ,���� ��������� comma+1
			if (comma == 2) {
				cAx[i][start] = inputdata[i][j];
				start++;
			}
			if (comma == 3) {
				cAy[i][start] = inputdata[i][j];
				start++;
			}
			if (comma == 4) {
				cAz[i][start] = inputdata[i][j];
				start++;
			}
			if (comma == 5) {
				cMx[i][start] = inputdata[i][j];
				start++;
			}
			if (comma == 6) {
				cMy[i][start] = inputdata[i][j];
				start++;
			}
			if (comma == 7) {
				cMz[i][start] = inputdata[i][j];
				start++;
			}
			if (comma == 8) {
				cGx[i][start] = inputdata[i][j];
				start++;
			}
			if (comma == 9) {
				cGy[i][start] = inputdata[i][j];
				start++;
			}
			if (comma == 10) {
				cGz[i][start] = inputdata[i][j];
				start++;
			}
		}
		comma = 0;
	}



	// �� ���ӵ�, ���ӵ�, ���ڱ� xyz���� �Ǽ��� ��ȯ�Ͽ� �����س���

	float temp = 0;

	for (int i = 0; i < len; i++) {

		if (cAx[i][0] == '*') {
			Ax[i] = Ax[i - 1];
		}
		else {
			temp = atof(cAx[i]);
			Ax[i] = temp;
			temp = 0;
		}
	}

	for (int i = 0; i < len; i++) {

		if (cAy[i][0] == '*') {
			Ay[i] = Ay[i - 1];
		}
		else {
			temp = atof(cAy[i]);
			Ay[i] = temp;
			temp = 0;
		}
	}

	for (int i = 0; i < len; i++) {

		if (cAz[i][0] == '*') {
			Az[i] = Az[i - 1];
		}
		else {
			temp = atof(cAz[i]);
			Az[i] = temp;
			temp = 0;
		}
	}

	for (int i = 0; i < len; i++) {

		if (cMx[i][0] == '*') {
			Mx[i] = Mx[i - 1];
		}
		else {
			temp = atof(cMx[i]);
			Mx[i] = temp;
			temp = 0;
		}
	}

	for (int i = 0; i < len; i++) {

		if (cMy[i][0] == '*') {
			My[i] = My[i - 1];
		}
		else {
			temp = atof(cMy[i]);
			My[i] = temp;
			temp = 0;
		}
	}

	for (int i = 0; i < len; i++) {

		if (cMz[i][0] == '*') {
			Mz[i] = Mz[i - 1];
		}
		else {
			temp = atof(cMz[i]);
			Mz[i] = temp;
			temp = 0;
		}
	}

	for (int i = 0; i < len; i++) {

		if (cGx[i][0] == '*') {
			Gx[i] = Gx[i - 1];
		}
		else {
			temp = atof(cGx[i]);
			Gx[i] = temp;
			temp = 0;
		}
	}

	for (int i = 0; i < len; i++) {

		if (cGy[i][0] == '*') {
			Gy[i] = Gy[i - 1];
		}
		else {
			temp = atof(cGy[i]);
			Gy[i] = temp;
			temp = 0;
		}
	}

	for (int i = 0; i < len; i++) {

		if (cGz[i][0] == '*') {
			Gz[i] = Gz[i - 1];
		}
		else {
			temp = atof(cGz[i]);
			Gz[i] = temp;
			temp = 0;
		}
	}



	
//state 1,2,3 -> Lf, Ll, Ld 
//state 4,5,6 -> Rf, Rl, Rd 
//state 7,8,9 -> Uf, Ul, Ud
//state 10,11,12 -> Df, Dl, Dd


	float leftcountArray[100] = { 0 };
	float rightcountArray[100] = { 0 };
	float upcountArray[100] = { 0 };
	float downcountArray[100] = { 0 };
	float doubleleftcountArray[100] = { 0 };
	float doubleupcountArray[100] = { 0 };
	float doublerightcountArray[100] = { 0 };
	float doubledowncountArray[100] = { 0 };

	int leftcount = 0;
	int rightcount = 0;
	int upcount = 0;
	int downcount = 0;
	int doubleleftcount = 0;
	int doubleupcount = 0;
	int doublerightcount = 0;
	int doubledowncount = 0;

	for (int i = 0; i < len; i++) {

		// left ���ۿ� ���� ���� idle ����

		if ((state == 0) && (Ax[i] > 10) && (Az[i] < 20) && (Az[i] > 7))
		{
			state = 1;
		}

		// idle -> left (first) ���·��� ����

		if (state == 1) {
			
			count++;
			if ((Ax[i] < -15) && (Gz[i] > 0) && ((Ax[i] + Gz[i] + Mx[i]) > 0)) {
				state = 2;
				count = 0;

			}
			if (count == 25)
			{
				state = 0;
				count = 0;

			}
		}

		// left (first) -> left (last) ���·��� ����

		if (state == 2) {
			
			count++;
			if ((Ax[i] > 5) && (Gz[i] < 0) && ((Ax[i] + Gz[i] + Mx[i]) < 0)) {
				state = 3;
				count = 0;

			}
			if (count == 25)
			{
				state = 0;
				count = 0;

			}
		}

		// left (last) -> left (determining) ���·��� ���� 
		// determining���� left�� ������

		if (state == 3) {

				count++;
				printf("left move\n");
				leftcountArray[leftcount] = i;
				leftcount++;
				count = 0;
				state = 0;

				i = i + 10;

				

				if ((Ax[i] < -15) && (Gz[i] > 0) && ((Ax[i] + Gz[i] + Mx[i]) > 0)) {
					
					doubleleftcountArray[doubleleftcount] = i;
					doubleleftcount++;
				
				}

		}


		if ((state == 0) && (Ax[i] < -10) && (Az[i] < 20) && (Az[i] > 9))
		{
			state = 4;
		}

		// idle -> right (first) ���·��� ����

		if (state == 4) {
			
			count++;
			if ((Ax[i] > 15) && (Gz[i] < 0) && ((Ax[i] + Gz[i] + Mx[i]) < 0)) {
				state = 5;
				count = 0;

			}
			if (count == 25)
			{
				state = 0;
				count = 0;

			}

		}

		// right (first) -> right (last) ���·��� ����

		if (state == 5) {
			
			count++;
			if ((Ax[i] < -5) && (Gz[i] > 0) && ((Ax[i] + Gz[i] + Mx[i]) > 0)) {
				state = 6;
				count = 0;

			}
			if (count == 25)
			{
				state = 0;
				count = 0;

			}
		}

		// right (last) -> right (determining) ���·��� ���� 
		// determining���� right�� ������

		if (state == 6) {
			
				count++;
				printf("right move\n");
				rightcountArray[rightcount] = i;
				rightcount++;
				count = 0;
				state = 0;
				i = i + 10;

			

				if ((state == 0) && (Ax[i] < -10) && (Az[i] < 20) && (Az[i] > 9))
				{
					doublerightcountArray[doublerightcount] = i;
					doublerightcount++;

				}

		
		}



		if ((state == 0) && (Az[i] > 20) && (Ax[i] < 10) && (Ax[i] > -10))
		{
			state = 7;
		} 

		// idle -> up (first) ���·��� ����

		if (state == 7) {

			count++;
			if ((Az[i] < -5) && (Gx[i] < 0) && ((Az[i] + Gx[i] + My[i]) < 10)) {
				state = 8;
				count = 0;

			}
			if (count == 25)
			{
				state = 0;
				count = 0;

			}
		}

		// up (first) -> up (last) ���·��� ����

		if (state == 8) {

			count++;
			if ((Az[i] > 15) && (Gx[i] > 0) && ((Az[i] + Gx[i] + My[i]) > 10)) {
				state = 9;
				count = 0;

			}
			if (count == 25)
			{
				state = 0;
				count = 0;

			}


		}

		// up (last) -> up (determining) ���·��� ���� 
		// determining���� up�� ������

		if (state == 9) {


			count++;
			printf("up move\n");
			upcountArray[upcount] = i;
			upcount++;
			count = 0;
			state = 0;
			i = i + 10;

		

			if ((state == 0) && (Az[i] > 20) && (Ax[i] < 10) && (Ax[i] > -10))
			{
				doubleupcountArray[doubleupcount] = i;
				doubleupcount++;
			}

		}


		if ((state == 0) && (Az[i] < -3))
		{
			state = 10;
		}

		// idle -> down (first) ���·��� ����

		if (state == 10) {
			count++;

			if ((Az[i] > 25) && (Gx[i] > 0) && ((Az[i] + Gx[i] + My[i]) > 10)) {

				state = 11;
				count = 0;

			}
			if (count == 25)
			{
				state = 0;
				count = 0;

			}
		}

		// down (first) -> down (last) ���·��� ����

		if (state == 11) {
			count++;
			
			if ((Az[i] < -1) && (Gx[i] < 0) && ((Az[i] + Gx[i] + My[i]) < 10)) {
				state = 12;
				count = 0;

			}
			if (count == 25)
			{
				state = 0;
				count = 0;

			}
		}

		// down (last) -> down (determining) ���·��� ���� 
		// determining���� down�� ������

		if (state == 12) {
			count++;
			printf("down move\n");
			downcountArray[downcount] = i;
			downcount++;
			count = 0;
			state = 0;
			i = i + 10;

			

			if ((state == 0) && (Az[i] < -3))
			{
				doubledowncountArray[doubledowncount] = i;
				doubledowncount++;
			}

		}

		

		if (state == 0) {
			printf("%d\tidle\t%d\t%f\t%f\t%f\t%f\t%f\t%f\n", i, count, Ax[i], Gz[i], Az[i], Gx[i], Mx[i], My[i]);
		}
		if (state == 1) {
			printf("%d\tLf\t%d\t%f\t%f\t%f\t%f\t%f\t%f\n", i, count, Ax[i], Gz[i], Az[i], Gx[i], Mx[i], My[i]);
		}
		if (state == 2) {
			printf("%d\tLl\t%d\t%f\t%f\t%f\t%f\t%f\t%f\n", i, count, Ax[i], Gz[i], Az[i], Gx[i], Mx[i], My[i]);
		}
		if (state == 4) {
			printf("%d\tRf\t%d\t%f\t%f\t%f\t%f\t%f\t%f\n", i, count, Ax[i], Gz[i], Az[i], Gx[i], Mx[i], My[i]);
		}
		if (state == 5) {
			printf("%d\tRl\t%d\t%f\t%f\t%f\t%f\t%f\t%f\n", i, count, Ax[i], Gz[i], Az[i], Gx[i], Mx[i], My[i]);
		}
		if (state == 7) {
			printf("%d\tUf\t%d\t%f\t%f\t%f\t%f\t%f\t%f\n", i, count, Ax[i], Gz[i], Az[i], Gx[i], Mx[i], My[i]);
		}
		if (state == 8) {
			printf("%d\tUl\t%d\t%f\t%f\t%f\t%f\t%f\t%f\n", i, count, Ax[i], Gz[i], Az[i], Gx[i], Mx[i], My[i]);
		}
		if (state == 10) {
			printf("%d\tDf\t%d\t%f\t%f\t%f\t%f\t%f\t%f\n", i, count, Ax[i], Gz[i], Az[i], Gx[i], Mx[i], My[i]);
		}
		if (state == 11) {
			printf("%d\tDl\t%d\t%f\t%f\t%f\t%f\t%f\t%f\n", i, count, Ax[i], Gz[i], Az[i], Gx[i], Mx[i], My[i]);
		}
	
		
	}



	for (int i = 0; i < 100; i++)
	{
		if (leftcountArray[i] == 0) { break; }
		printf("left:%f\n", leftcountArray[i] * 0.02);
	}//���� ���� Ƚ�� �� ���� �ð� (1-> 0.02��)
	for (int i = 0; i < 100; i++)
	{
		if (rightcountArray[i] == 0) { break; }
		printf("right:%f\n", rightcountArray[i] * 0.02);
	}//������ ���� Ƚ�� �� ���� �ð� (1-> 0.02��)
	for (int i = 0; i < 100; i++)
	{
		if (upcountArray[i] == 0) { break; }
		printf("up:%f\n", upcountArray[i] * 0.02);
	}//�� ���� Ƚ�� �� ���� �ð� (1-> 0.02��)
	for (int i = 0; i < 100; i++)
	{
		if (downcountArray[i] == 0) { break; }
		printf("down:%f\n", downcountArray[i] * 0.02);
	}//�Ʒ� ���� Ƚ�� �� ���� �ð� (1-> 0.02��)
	for (int i = 0; i < 100; i++)
	{
		if (doubleleftcountArray[i] == 0) { break; }
		printf("doubleleft");
	}//���� ���� ���� ǥ��
	for (int i = 0; i < 100; i++)
	{
		if (doubleupcountArray[i] == 0) { break; }
		printf("doubleup");
	}//���� ���� ���� ǥ��
	for (int i = 0; i < 100; i++)
	{
		if (doublerightcountArray[i] == 0) { break; }
		printf("doubleright");
	}//���� ������ ���� ǥ��
	for (int i = 0; i < 100; i++)
	{
		if (doubledowncountArray[i] == 0) { break; }
		printf("doubledown");
	}//���� �Ʒ� ���� ǥ��
	if (leftcountArray[0] == 0 && rightcountArray[0] == 0 && upcountArray[0] == 0 && downcountArray[0] == 0 && doubleleftcountArray[0] == 0 && doubleupcountArray[0] == 0 && doublerightcountArray[0] == 0)
	{
		printf("can't detect anything");
	}
}   //�ƹ��͵� ��ġ���ҽÿ� ��ã�Ҵٴ� �޼��� ǥ��