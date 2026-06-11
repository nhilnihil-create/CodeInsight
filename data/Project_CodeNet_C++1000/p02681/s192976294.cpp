
// Problem : A - Registration
// Contest : AtCoder - AtCoder Beginner Contest 167
// URL : https://atcoder.jp/contests/abc167/tasks/abc167_a
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a,b;
	cin>>a>>b;
	string k = b.substr(0,(int) a.size());
	if(k == a)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	return 0;
}