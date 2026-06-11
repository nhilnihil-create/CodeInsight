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
	ll n,k,i,j,l,m;
	cin>>n>>k;
	ll arr[n];
	for(i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,arr+n);
	l=0;
	for(i=0;i<n-k;i++)
		l+=arr[i];
	cout<<l<<"\n";
	return 0;
}
