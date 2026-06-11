#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<string>
#include<cmath>
#include<cstdio>
#include<cctype>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<set>
#include<map>
#include<utility>
#include<vector>
#include<stack>
#include<sstream>
#include<algorithm>
using namespace std;
/****************************/
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vpii vector<pair<int,int> >
#define qi queue<int>
#define mii map<int,int>
#define msi map<string,int>
/****************************/
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(i,n) for(ll i=(n)-1;i>=0;i--)
#define rep3(i,a,n) for(ll i=(a);i<(n);i++)
#define mp make_pair
#define pb push_back
#define st first
#define nd second
#define pi 3.1415926535897932384626433832795
#define zero(n) memset(n,0,sizeof(n));
#define SZ(n) n.size()
#define ss st.st
#define sn st.nd 
#define mod 1000000007
/****************************/
using namespace std;
int n;
ll dp[2010];
int main()
{
	cin>>n;
	zero(dp);
	ll sum=0;
	dp[0]=1;
	rep3(i,3,n+1)
	{
		sum+=dp[i-3];
		sum%=mod;
		dp[i]+=sum;
	 }
	 cout<<dp[n];
	return 0;
}