#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
/*---------------------DEBUGGING--------------------------------------------*/
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
/*-------------------------------------------------------------------------------------*/
//#define mp make_pair
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define pcc pair<char,char>
#define F first
#define S second
#define int long long
#define pi 3.141592653589793238462643383279502
#define M  1000000007
#define rep(i,a,n) for(int i=a;i<n;i++)
#define INF 10000000000000
#define N 100005
#define vi vector<int>
#define all(v) v.begin(),v.end()
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
int dp[2005][2005];
int sum[2005][2005];
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int n,m;
   cin>>n>>m;
   int s[n+1],t[m+1];
   rep(i,1,n+1)cin>>s[i];
   rep(i,1,m+1)cin>>t[i];
   dp[0][0]=1;
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=m;j++)
       {
           if(s[i]==t[j])
           {
               (dp[i][j]=sum[i-1][j-1]+1)%=M;
           }
           (sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+dp[i][j] + M)%=M;

       }
   }
   int ans=0;
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=m;j++)
        {ans+=dp[i][j];ans%=M;}
   }
   ans++;
   cout<<((ans+M)%M)<<endl;
}

