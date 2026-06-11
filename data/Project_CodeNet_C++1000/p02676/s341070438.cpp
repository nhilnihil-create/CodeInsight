
// Problem : B - ... (Triple Dots)
// Contest : AtCoder - AtCoder Beginner Contest 168
// URL : https://atcoder.jp/contests/abc168/tasks/abc168_b
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin>>k;
	string s;
	cin>>s;
	if((int) s.size() <= k)
	{
		cout<<s;
	}
	else
	{
		string t = s.substr(0, k);
		t = t + "...";
		cout<<t;
	}
	return 0;
}