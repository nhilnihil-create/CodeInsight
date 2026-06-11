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
	ll n,i,j,k,l,m,z;
	cin>>n;
	ll arr[n];
	l=0;
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
		l+=arr[i];
	}
	k=0;
	m=l-arr[0];
	for(i=0;i<n-1;i++)
	{
		k+=arr[i];
		z=l-k;
		if(m>abs(z-k))
			m=abs(z-k);
	}
	cout<<m<<"\n";
	return 0;
}
	
