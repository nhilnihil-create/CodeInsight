#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,b=0,g=0,r=0;
	string s;
	cin>>n>>s;
	for(long long i=0;i<s.length();i++)
	{
		if(s[i]=='B')	b++;
		if(s[i]=='G')	g++;
		if(s[i]=='R')	r++;
	}
	long long ct=b*g*r;
	//cout<<b<<" "<<g<<" "<<r<<" "<<b*g*r<<endl;
	for(long long i=0;i<n;i++)
	{
		for(long long j=i;j<n;j++)
		{
			long long pos=j+j-i;
			if(pos<n && s[pos]!=s[i] && s[i]!=s[j] && s[j]!=s[pos]) 	ct--;
		}
	}
	cout<<ct;
	return 0;
}