#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int a, b;
	int i;
	int ans=-1;
	cin >> a >> b;
	int tmp;
	if (a > b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	for (i = a; i < b; i++)
	{
		if ((a - i) * (-1) == b - i)
		{
			ans = i;
			break;
		}
	}
	if (ans == -1)
		cout << "IMPOSSIBLE" << endl;
	else
		cout << ans << endl;
}