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
int fac[N];
vi adj[N];
bool vis[N]={false};
int power(int x, int y, int p)
{
    int res = 1;     // Initialize result

    x = x % p; // Update x if it is more than or
                // equal to p

    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}

int modinv(int n)
{
    return power(n,M-2LL,M);
}
int nPr(int n,int r)
{   if(n < r)return 0;
    return (fac[n]*modinv(fac[n-r]))%M;
}
signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   fac[0]=1;
   for(int i=1;i<N;i++)
   {
       fac[i]=(fac[i-1]*i)%M;
   }
   int n,k;
   cin>>n>>k;
   rep(i,0,n-1)
   {
       int u,v;
       cin>>u>>v;
       adj[u].pb(v);
       adj[v].pb(u);
   }
   int ans=1;
   ans*=k;
   for(int i=1;i<=n;i++)
   {
       if(i == 1)
       {
           int x=adj[i].size();
           ans*=(nPr(k-1,x));
           ans%=M;
       }
       else
       {
           int x=adj[i].size()-1;
           if(x == 0)continue;
           ans*=(nPr(k-2,x));
           ans%=M;
       }
   }
   //debug(nPr(22,1));
   cout<<(ans)%M<<endl;
}

