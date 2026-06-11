#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 510
using namespace std;

int arr[MAX][MAX];

int main(void)
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			int cur = 1;
			int ii = i;
			int jj = j;
			while ((ii % 2 == 0) ^ (jj % 2 == 0) == false)
			{
				ii /= 2;
				jj /= 2;
				cur++;
			}
			arr[i][j] = cur;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++) cout << arr[i][j] << " ";
		cout << endl;
	}
	return 0;
}
