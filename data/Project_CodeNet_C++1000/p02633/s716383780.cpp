#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int x;
	cin >> x;
	int cnt = 0;
	int a = 0;
	while (1)
	{
		a += x;
		cnt++;
		if (a % 360==0)
			break;
		if (a > 360)
			a -= 360;
	}
	cout << cnt << endl;
} 