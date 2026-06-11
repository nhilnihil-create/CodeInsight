#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int n;
	cin >> n;
	vector<int>a(n), b(n), c(n - 1);
	int i;
	int bef = 0, aft = 0;;
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		cin >> a.at(i);
	}
	for (i = 0; i < n; i++)
	{
		cin >> b.at(i);
	}
	for (i = 0; i < n-1; i++)
	{
		cin >> c.at(i);
	}
	for (i = 0; i < n; i++)
	{
		sum += b.at(a.at(i) - 1);
		if (i >= 1)
		{
			if (a.at(i) - a.at(i - 1) == 1)
			{
				sum += c.at(a.at(i-1) - 1);
			}
		}
	}
	cout << sum << endl;
}