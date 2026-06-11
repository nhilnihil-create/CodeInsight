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
		ll  n,i,j,k;
		cin>>n;
		string str,s1,s2;
		cin>>str;
		s1="";
		for(i=0;i<n/2;i++)
		{
			s1+=str[i];
		}
		s2="";
		for(j=i;j<n;j++)
			s2+=str[j];
		if(s1==s2)
			cout<<"Yes\n";
		else
			cout<<"No\n";
		return 0;
}
	