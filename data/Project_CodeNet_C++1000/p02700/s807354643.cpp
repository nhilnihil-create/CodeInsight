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
	ll a,b,c,d,i,j,k,l;
	cin>>a>>b>>c>>d;
	while(1)
	{
		c=c-b;
		if(c<=0)
		{
			cout<<"Yes\n";
			break;
		}
		a=a-d;
		if(a<=0)
		{
			cout<<"No\n";
			break;
		}
	}
	return 0;
}
	