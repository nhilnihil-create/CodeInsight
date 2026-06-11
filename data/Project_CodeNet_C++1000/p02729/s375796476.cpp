#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int n, m;
	cin >> n >> m;
	int i, j;
	int cnt = 0;
	for (i = 1; i < n; i++)
	{
		for (j = i + 1; j <= n; j++)
		{
			cnt++;
		}
	}
	for (i = 1; i < m; i++)
	{
		for (j = i + 1; j <= m; j++)
		{
			cnt++;
		}
	}
	cout << cnt << endl;

}