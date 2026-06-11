
// Problem : A - Sheep and Wolves
// Contest : AtCoder - AtCoder Beginner Contest 164
// URL : https://atcoder.jp/contests/abc164/tasks/abc164_a
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int s,w;
	cin>>w>>s;
	if(s < w)
	{
		cout<<"safe";
	}
	else
	{
		cout<<"unsafe";
	}
	return 0;
}