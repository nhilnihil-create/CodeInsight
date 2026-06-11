
// Problem : A - Circle Pond
// Contest : AtCoder - AtCoder Beginner Contest 163
// URL : https://atcoder.jp/contests/abc163/tasks/abc163_a
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	double pi = 3.141592653589793238;
	int n;
	cin>>n;
	double ans = n * 1.00;
	ans = ans * 2.0;
	ans = ans * pi;
	cout<<setprecision(20)<<ans<<"\n";
	return 0;
}