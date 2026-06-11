#include<iostream>
#include<bits/stdc++.h>
#define int long long
#define mod 1000000007
#define pb(x) push_back(x)
#define gcd(a,b) __gcd(a,b)
#define all(v) v.begin(),v.end()
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int32_t main()
{
string s;
cin>>s;
int n=s.size();
for(int i=0;i<s.size();i++)
{
	if(s[i]=='?')
	{
		if(i==0)
		{
			if(s[i+1]=='P')
			{
				s[i]='D';
			}
			else
			{
				s[i]='D';
			}
		}
		else if(i==n-1)
		{
			if(s[i-1]=='P')
			{
				s[i]='D';
			}
			else
			{
				s[i]='D';
			}
		}
		else
		{
			if(s[i+1]=='P' && s[i-1]=='D')
			{
				s[i]='D';
			}
			else if(s[i+1]=='D' && s[i-1]=='P')
			{
				s[i]='D';
			}
			else if(s[i+1]=='D' && s[i-1]=='D')
			{
				s[i]='D';
			}
			else
			{
				s[i]='D';
			}
		}
		
	}
}
cout<<s;
}
