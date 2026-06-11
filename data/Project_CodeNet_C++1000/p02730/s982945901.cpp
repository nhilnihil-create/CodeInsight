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
		string str;
		ll n,i,j,k,l,m;
		cin>>str;
		if(isPalindrome(str))
		{
			string s1="";
			n=str.length();
			for(i=0;i<(n-1)/2;i++)
				s1+=str[i];
			if(isPalindrome(s1))
			{
				string s2="";
				for(i=((n+3)/2)-1;i<n;i++)
					s2+=str[i];
				if(isPalindrome(s2))
					cout<<"Yes\n";
				else
					cout<<"No\n";
			}
			else
				cout<<"No\n";
		}
		else
		{
			cout<<"No\n";
		}
		return 0;
}
	