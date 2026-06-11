#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	long long int n, k;
	cin >> n >> k;
	int cnt=0;
	for (int i = 1; i < 1000; i++)
	{
		if (pow(k, i) > n)
		{
			cnt = i;
			break;
		}
	}
	cout << cnt << endl;
}