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
	double w,h,x,y;
	cin>>w>>h>>x>>y;
	cout<<fixed<<setprecision(6)<<w*h/2<<" ";
	if(2*x-w==0 && 2*y-h==0)
		cout<<1<<"\n";
	else
		cout<<0<<"\n";
	return 0;
}
	
