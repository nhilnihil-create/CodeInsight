#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<stack>
#include<iostream>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define vec(a) vector<int>a
using namespace std;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
	fastio
	string str;
	ll n,i,j,k,l;
	cin>>n;
	set<string> se;
	while(n--)
	{
		cin>>str;
		se.insert(str);
	}
	cout<<se.size()<<"\n";
	return 0;
}
	