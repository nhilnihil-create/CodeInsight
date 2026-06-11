#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int n, l;
	cin >> n >> l;
	int sum = 0;
	int a = 0;
	int min = 300;
	int i;
	for (i = 1; i <=  n; i++)
	{
		sum += l + i - 1;
		if (abs(l + i - 1) < min)
		{
			min = abs(l + i - 1);
			a = l + i - 1;
		}
	}
	cout << sum - a << endl;
}