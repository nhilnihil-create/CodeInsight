#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int n, m;
	cin >> n >> m;
	vector<int>a(n);
	int i;
	for (i = 0; i < m; i++)
	{
		cin >> a.at(i);
		n = n - a.at(i);
	}
	if (n < 0)
		n = -1;
	cout << n << endl;
} 