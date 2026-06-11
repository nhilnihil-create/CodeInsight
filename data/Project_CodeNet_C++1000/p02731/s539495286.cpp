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

bool isPalindrome(string str)
{
	ll i,j,k,l,n;
	l=str.length();
	for(i=0;i<l/2;i++)
	{
		if(str[i]==str[l-i-1])
			continue;
		else
			return 0;
	}
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
		double x,y;
		cin>>x;
		y=x/3;
		y=y*y*y;
		cout<<fixed<<setprecision(12)<<y<<"\n";
		return 0;
}
	