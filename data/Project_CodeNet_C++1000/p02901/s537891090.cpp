#include<iostream>
#include<stdio.h>
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
#define N 200005
#define vi vector<int>
#define all(v) v.begin(),v.end()
//#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
int dp[1<<12];

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   int n,m;
   cin>>n>>m;
   int a[m];
   int cost[m];
   for(int i=0;i<m;i++)
   {
       cin>>cost[i];
       int k;
       cin>>k;
       int val=0;
       for(int j=0;j<k;j++)
       {
           int x;cin>>x;
           x--;
           val+=(1LL<<x);
       }
       a[i]=val;
   }
   memset(dp,0x3f,sizeof(dp));
   dp[0]=0;
   int full_mask=(1LL<<n)-1;
   for(int mask=0;mask<=full_mask;mask++)
   {
       for(int i=0;i<m;i++)
       {
           dp[a[i]|mask]=min(dp[a[i]|mask],dp[mask]+cost[i]);
       }
   }
   if(dp[full_mask]>1e18)
    cout<<-1<<endl;
   else
   cout<<dp[full_mask]<<endl;



}

