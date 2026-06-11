#include<iostream>
#include<cstdio>
#include<algorithm>
#include<math.h>
#include<vector>
#define Lens 1000005
#define Nil -1
using namespace std;

int N, sum;
int a[Lens];
vector<int> b, G;
void selectionsort(int a[], int g)
{
	for (int i = g; i < N; i++)
	{
		int j = i - g;
		int mini = a[i];
		while (j >= 0 && a[j] > mini)
		{

			a[j + g] = a[j];
			sum++;
			j -= g;
		}
		a[j + g] = mini;
	}
}

void shell()
{
	int h = 1;
	while (h <= N)
	{
		G.push_back(h);
		h = 3 * h + 1;
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	shell();
	sum = 0;
	cout << G.size() << endl;
	for (int i = G.size() - 1; i >= 0; i--)
	{

		cout << G[i];
		if (i > 0)
			cout << ' ';
		if (i == 0)
			cout << endl;
	}


	for (int i = G.size() - 1; i >= 0; i--)
	{
		int g = G[i];
		selectionsort(a, g);
	}
	cout << sum << endl;
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << endl;
	}
	return 0;
}
