#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	long long int a, b,k;
	cin >> a >> b >> k;
	if (a >= k)
	{
		a = a - k;
		k = 0;
	}
	else
	{
		k = k - a;
		a = 0;
		
	}
	b = b - k;
	if (b <= 0)
		b = 0;
	cout << a <<" "<< b<<endl;
}