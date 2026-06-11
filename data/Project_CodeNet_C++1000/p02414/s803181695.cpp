#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void DEBUGPrint(unsigned long ary[][100], int row, int col)
{
	printf("*DEBUG:BEGIN*********\n");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (j == col-1)
				printf("%d\n", ary[i][j]);
			else
				printf("%d ", ary[i][j]);
		}
	}
	printf("*DEBUG:END *********\n");
}
void Print(unsigned long ary[][100], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (j == col-1)
				printf("%lu\n", ary[i][j]);
			else
				printf("%lu ", ary[i][j]);
		}
	}
}

// ????´???????????????????????????°?????????????????????
int main()
{
	int n,m,l;
	int num;
	
	unsigned long A[100][100] = {0};
	unsigned long B[100][100] = {0};
	unsigned long C[100][100] = {0};
	scanf("%d %d %d", &n, &m, &l);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x;
			scanf("%lu", &x);
			A[i][j] = x;
		}
	}
	//DEBUGPrint(A, n, m);
	
	for (int i = 0; i < m; i++)
	{
		for (int k = 0; k < l; k++)
		{
			int x;
			scanf("%lu", &x);
			B[i][k] = x;
		}
	}
	//DEBUGPrint(B, n, m);
	
	//printf("n=%d, l=%d****\n", n, l);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < l; j++)
		{
			long sum = 0;
			for (int k = 0; k < m; k++)
			{
			//	if (A[i][k] < 0 || A[i][k] > 10000)
			//		goto LABEL;
			//	if (B[i][k] < 0 || B[i][k] > 10000)
			//		goto LABEL;
				
				sum += (A[i][k] * B[k][j]);
			}
			C[i][j] = sum;
			//printf("i,j=%d,%d\n", i,j);
		}
	}
	//DEBUGPrint(C, n, l);
	Print(C, n, l);
	//goto END;
//LABEL:
//	printf("ERROR");
//END:
	
	return 0;
}