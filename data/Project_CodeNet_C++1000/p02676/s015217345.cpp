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
	ll n,i,j,k;
	cin>>n;
	k=n;
	string str;
	cin>>str;
	j=str.length();
	n=min(n,j);
	for(i=0;i<n;i++)
		cout<<str[i];
	if(j>k)
	cout<<"..."<<"\n";
}
	
