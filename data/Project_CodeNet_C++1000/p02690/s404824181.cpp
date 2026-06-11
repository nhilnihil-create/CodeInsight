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
	ll x;
	cin>>x;
	ll i,j;
	for(i=-150;i<=150;i++)
	{
		for(j=-150;j<=150;j++)
		{
			if(pow(i,5)-pow(j,5)==x)
			{
				cout<<i<<" "<<j<<"\n";
				return 0;
			}
		}
	}
	return 0;
}
	