#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<stack>
#include<iostream>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define MOD 1000000007
#define vec(a) vector<int>a
using namespace std;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
	fastio
	ll n,i,j,k,l;
	cin>>n;
	map<string,ll> m;
	while(n--)
	{
		string str;
		cin>>str;
		m[str]++;
	}
	map<string,ll>::iterator it;
	k=0;
	for(it=m.begin();it!=m.end();it++)
	{
		if(it->second>k)
			k=it->second;
	}
	for(it=m.begin();it!=m.end();it++)
	{
		if(it->second==k)
			cout<<it->first<<"\n";
	}
	return 0;
}
