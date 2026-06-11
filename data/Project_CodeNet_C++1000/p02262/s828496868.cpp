#include <iostream>
using namespace std;

int cnt = 0;

void insertionSort(int num[], int N, int g);
void shellSort(int num[], int N);
void showArray(int num[], int N);

int main()
{
	int N;
	cin >> N;
	int *num = new int[N];
	for(int i = 0; i < N; i++)
		cin >> num[i];
	shellSort(num, N);
	showArray(num, N);
}

void insertionSort(int num[], int N, int g)
{
	for(int i = g; i<N; i++)
	{
		int temp = num[i];
		int j = i-g;
		while(j >= 0 && num[j] > temp)
		{
			num[j+g] = num[j];
			j -= g;
			cnt++;
		}
		num[j+g] = temp;
	}
}

void shellSort(int num[], int N)
{
	int m = 0;
	int G[100];
	for(int i = 1; ; )
	{
		if(i >N)
			break;
		G[m] = i;
		m++;
		i = i*3+1;
	}

	cout<<m<<endl;
	for(int i = m-1; i >= 0; i--)
	{
		insertionSort(num, N, G[i]);
		cout<<G[i];
		if(i!=0)
			cout<<' ';
	}
	cout << endl << cnt << endl;
}

void showArray(int num[], int N)
{
	for(int i = 0; i < N; i++)
		cout <<num[i] << endl;
}