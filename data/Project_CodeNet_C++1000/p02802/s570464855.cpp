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
	ll n,m,i,j,k,l;
	cin>>n>>m;
	ll arr[n+1]={0},z=0,x=0,arr1[n+1]={0};
	for(i=0;i<m;i++)
	{
		string s;
		cin>>k>>s;
		if(arr[k]==0 && s=="WA")
			arr1[k]++;
		else if(arr[k]==0 && s=="AC")
		{
			arr[k]=1;
			x+=arr1[k];
			z++;
		}
	}
	cout<<z<<" "<<x;
}
	