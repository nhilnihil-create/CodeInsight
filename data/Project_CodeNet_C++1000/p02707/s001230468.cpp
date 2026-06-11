
// Problem : C - management
// Contest : AtCoder - AtCoder Beginner Contest 163
// URL : https://atcoder.jp/contests/abc163/tasks/abc163_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector <int> ele(n-1);
	for(int j = 0 ; j < n-1; j++)
	{
		cin>>ele[j];
	}
	map <int,int> pairs;
	for(int j = 1; j <= n; j++)
	{
		pairs.insert(make_pair(j,0));
	}
	for(int j = 0 ; j < n-1; j++)
	{
		auto it = pairs.find(ele[j]);
		it->second += 1;
	}
	for(auto it = pairs.begin() ; it != pairs.end(); it++)
	{
		cout<<it->second<<"\n";
	}
	return 0;
}