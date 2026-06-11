#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	long long int a;
	long double b;
	long long int ans;

	cin >> a >> b;
	b = b * 1000;
	ans = a * b/1000;
	cout << ans << endl;
}