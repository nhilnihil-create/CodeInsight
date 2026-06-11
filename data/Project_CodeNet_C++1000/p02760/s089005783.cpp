#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int a[3][3];
	int b[3][3] = { 0 };
	int n;

	int i, j, k;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			cin >> a[i][j];
		}
	}
	int sum = 0;
	cin >> n;
	vector<int>c(n);
	for (i = 0; i < n; i++)
		cin >> c[i];
	for (k = 0; k < n; k++)
	{
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (a[i][j] == c[k])
					b[i][j] = 1;
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		sum += (b[0][i] * b[1][i] * b[2][i]);
		sum += (b[i][0] * b[i][1] * b[i][2]);
	}
	sum += (b[0][0] * b[1][1] * b[2][2]);
	sum += (b[0][2] * b[1][1] * b[2][0]);
	if (sum >= 1)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
}