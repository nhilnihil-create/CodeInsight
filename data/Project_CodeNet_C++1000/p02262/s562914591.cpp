#include <iostream>
using namespace std;
int cnt;
int n;
int A[1000000];
int h = 1;

void insertionSort(int A[], int n,int g);
void shellSort(int A[], int n);

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> A[i];

	shellSort(A, n);

	cout << cnt << endl;

	for(int i = 0; i < n; i++)
		cout << A[i] << endl;
	return 0;
}

void insertionSort(int A[], int n, int g)
{
	for(int i = g; i < n; i++)
	{
		int v = A[i];
		int j = i - g;
		while(j >= 0 && A[j] > v)
		{
			A[j + g] = A[j];
			j = j - g;
			cnt++;
		}
		A[j + g] = v;
	}
}

void shellSort(int A[], int n)
{
	cnt = 0;
	//int m = 1;
	int G[100];
	int num = 0;
	while(1)
	{
		G[num++] = h;
		h = 3 * h + 1;
		if(h > n)
			break;
	}
	for(int i = num - 1; i >= 0; i--)
		insertionSort(A, n, G[i]);

	cout << num << endl;
	for(int i = num - 1; i >= 0; i--)
	{
		if(i != num - 1)
			cout << " ";
		cout << G[i];
	}
	cout << endl;
}