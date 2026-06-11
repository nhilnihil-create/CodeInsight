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
	ll n,i,j,k,l,m;
	cin>>n;
	ll arr[n];
	k=0;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i]%2==0)
		{
			if(arr[i]%3==0 || arr[i]%5==0)
				continue;
			k=1;
			break;
		}
	}
	if(k==1)
		cout<<"DENIED\n";
	else
		cout<<"APPROVED\n";

	return 0;
}
	