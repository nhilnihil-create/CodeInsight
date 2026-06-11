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
	ll k,x,i,j,l,m;
	cin>>k>>x;
	i=x-k+1;
	for(j=0;j<2*k-1;j++)
	{
		cout<<i<<" ";
		i++;
	}
	//cout<<"\n";
	return 0;
}
	
