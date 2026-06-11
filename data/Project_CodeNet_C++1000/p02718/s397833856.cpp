#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int n, m;
	double h;
	cin >> n >> m;

	h = 1.0 / (4 * double(m));
	int cnt = 0;
	vector<int>a(n);
	int i;
	int b=0;
	for (i = 0; i < n; i++)
	{
		cin >> a.at(i);
		b = b + a.at(i);
	}
	for (i = 0; i < n; i++)
	{
		if (4 * m * a.at(i) >= b)
			cnt++;
	}
	if (cnt >= m)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
} 