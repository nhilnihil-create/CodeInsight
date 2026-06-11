#include "bits/stdc++.h"
using namespace std;
#define rep(i,n)for(int i=0;i<(int)(n);i++)
#define PI 3.141592653589793
//vector < vector<int>>a(0, vector<int>(0));二次元配列宣言


int main()
{
	int n;
	cin >> n;
	vector<int>a(n);
	int i;
	double ans=0;
	for (i = 0; i < n; i++)
	{
		cin >> a.at(i);
		ans += (double)(1.0 / a.at(i));
		//cout << ans << endl;
	}
	ans = 1 / ans;
	printf("%.10f\n", ans);
}
