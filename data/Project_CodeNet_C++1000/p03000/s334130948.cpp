#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int x, n;
	cin >> n >> x;
	vector<int>l(n);
	int i;
	int cnt = 1;
	int sum = 0;
	for (i = 0; i < n; i++)
	{
		cin >> l.at(i);
	}
	i = 2;
	while (n+1 >= i)
	{
		sum = sum + l.at(i - 2);
		if (sum <= x)
			cnt++;
		else
			break;
		i++;
	}
	cout << cnt << endl;
}