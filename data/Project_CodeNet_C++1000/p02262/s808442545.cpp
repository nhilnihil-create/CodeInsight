#include <stdio.h>
#include <iostream>

using namespace std;

int cnt = 0;
int A[1000000];

void print(int N, int *A) 
{

	for (int i = 0; i < N; i++)
	{
		cout << A[i];
		if (i == N - 1) 
		{
			//do nothing
		}
		else
		{
			cout << endl;
		}
	}
}


void inserSort(int N, int *A,int B)
{
	int v;
	int j;

	for (int i = B; i < N; i++)
	{
		v = A[i];
		j = i - B;

		while (j >= 0 && A[j] > v)
		{
			A[j + B] = A[j];
			j = j - B;
			cnt++;
		}

		A[j+B] = v;
	}
}

void shellSort(int N,int *A) 
{
	int j = 0,i=0, h=0, B[10000];

	while (true)
	{
		B[i] = 3 * h + 1;
		h = B[i];
		if ((3 * h + 1) > N) 
		{
			break;
		}
		i++;
	}
	cout << (i+1) << endl;
	for (int j = i; j >= 0; j--)
	{
		printf("%d", B[j]);
		inserSort(N,A,B[j]);
		if (j != 0) 
		{
			cout << " ";
		}
		else
		{
			cout << endl;
		}
	}
	printf("%d", cnt);
	cout << endl;
	print(N, A);

}

int main()
{
	int N,i=0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	shellSort(N, A);

	return 0;
}
