#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	long long int n, a, b;
	cin >> n >> a >> b;
	long long int c, sum = 0;
	sum += n / (a + b) * a;
	c = n % (a + b);
	if (c <= a)
		sum += c;
	else
		sum += a;
	cout << sum << endl;
}