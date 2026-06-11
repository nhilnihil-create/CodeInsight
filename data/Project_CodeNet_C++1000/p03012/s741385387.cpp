#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int n;
	cin >> n;
	vector<int>w(n);
	int i;
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		cin >> w.at(i);
	}
	int a, b,c,d;
	a = b = c=0;
	d = n - 1;
	int cnt = 0;
	while (cnt < n)
	{
		if (a <= b)
		{
			a += w.at(c);
			c++;
		}
		else
		{
			b += w.at(d);
			d--;
		}
		cnt++;
	}
	cout << abs(a - b) << endl;


}