#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define inf 100000000
#define mod 1000000007
#define ld long double
#define point complex<double>
#define pi  acos(-1)
#define IO                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
using namespace std;

string s;
	int convert(string s)
	{
		int res=0;
		for(int i=s.size()-1;i>=0;i--)
		{
			res+=pow(26,(s.size()-1)-i)*(s[i]-'a');
		}
		return res;
	}
ll dp[200001][3] ;
	ll solve(int cur ,int last)
	{
		
		if(cur>=s.size())
		{
			return 0;
		}
		if(dp[cur][last]!=-1)return dp[cur][last];
		string llast="";
		if(last==2)
		{
			llast=s[cur-2]+s[cur-1];
		}
		else if(last==1)
		{
			llast=s[cur-1];
		}
		string s1="",s2="";
		
			s1=s[cur];
	    if(cur+1<s.size())
		{
			s2=s[cur]+s[cur+1];
		}
		ll res=0;
		if(llast!=s1)
		res=solve(cur+1,1)+1;
		if(llast!=s2&&cur+2<s.size())
		res=max(res,solve(cur+2,2)+1);
		
		return dp[cur][last]=res;
	}

	int main(){
	cin>>s;
	memset(dp,-1,sizeof(dp));
	cout<<max(solve(1,1),solve(2,2))+1;
    return 0;
}
