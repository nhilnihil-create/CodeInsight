
// Problem : B - Homework
// Contest : AtCoder - AtCoder Beginner Contest 163
// URL : https://atcoder.jp/contests/abc163/tasks/abc163_b
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

int  main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long int  d,n;
	cin>>d>>n;
	vector <long long int > ele(n);
	for(long long int  j = 0 ; j < n; j++)
	{
		cin>>ele[j];
	}
	long long int  sum = 0;
	for(long long int  j = 0 ; j < n; j++)
	{
		sum += ele[j];
	}
	if(sum > d)
	{
		cout<<"-1"<<"\n";
	}
	else
	{
		long long int  ans = d - sum;
		cout<<ans<<"\n";
	}
	return 0;
}