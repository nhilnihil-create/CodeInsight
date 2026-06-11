
// Problem : B - Easy Linear Programming
// Contest : AtCoder - AtCoder Beginner Contest 167
// URL : https://atcoder.jp/contests/abc167/tasks/abc167_b
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

int  main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long int  a,b,c,k;
	cin>>a>>b>>c>>k;
	long long int  x = a + b;
	if(k <= x)
	{
		cout<<min(a,k)<<"\n";
	}
	else
	{
		long long int  ans = a;
		ans -= (k-x);
		cout<<ans;
	}
	return 0;
}