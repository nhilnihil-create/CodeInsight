#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int n;
	cin >> n;
	int i, j;
	vector<int>d(n);
	for (i = 0; i < n; i++)
	{
		cin >> d.at(i);
	}
	int sum = 0;
	for (i = 0; i < n-1; i++)
	{
		for (j = i+1; j < n; j++)
		{
			sum += (d.at(i) * d.at(j));
		}
	}
	cout << sum << endl;
	
}