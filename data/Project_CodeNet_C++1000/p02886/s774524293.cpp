#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<stack>
#include<iostream>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define vec(a) vector<int>a
using namespace std;
//fibonacci
int binet(int n)
{
	return (pow((1+sqrt(5)),n-1)-pow((1-sqrt(5)),n-1))/(pow(2,n-1)*sqrt(5));
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
	fastio
	ll n,i,j,k,m,l;
	cin>>n;
	ll arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];
	k=0;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(i!=j)
			{
				k+=(arr[i]*arr[j]);
			}
		}
	}
	cout<<k<<"\n";
	return 0;
}