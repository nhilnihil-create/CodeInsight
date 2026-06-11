
// Problem : E - Red Scarf
// Contest : AtCoder - AtCoder Beginner Contest 171
// URL : https://atcoder.jp/contests/abc171/tasks/abc171_e
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll i,j,k,m,n,t,q;
	cin>>n;
	ll ar[n];
	for(i=0;i<n;i++)
	cin>>ar[i];
	ll pre[n],suf[n];
	pre[0]=ar[0];
	for(i=1;i<n;i++)
	{
		pre[i]=pre[i-1]^ar[i];
	}
	suf[n-1]=ar[n-1];
	for(i=n-2;i>=0;i--)
	{
		suf[i]=suf[i+1]^ar[i];
	}
	cout<<suf[1]<<' ';
	for(i=1;i<n-1;i++)
	cout<<(suf[i+1]^pre[i-1])<<' ';
	cout<<pre[n-2]<<' ';
}