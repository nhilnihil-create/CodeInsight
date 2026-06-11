// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define pb push_back
#define all(_obj) _obj.begin(),_obj.end()
#define F first
#define S second
#define INF 1e18
#define pll pair<ll, ll> 
#define vll vector<ll>
ll n,m,a,b,c,k,temp,x,y;
const int MAXN=1e6+11,mod=1e9+7;
inline ll max(ll a,ll b) {return ((a>b)?a:b);}
inline ll min(ll a,ll b) {return ((a>b)?b:a);}
inline vll read(int n) {vll v(n);for (int i = 0; i < v.size(); i++)cin>>v[i];return v;}
vll v[MAXN];
void sol(void)
{
cin>>n;
for(ll i=1;i*i<=n;i++)
for(ll j=i*i;j<=n;j+=i) 
v[j].pb(i);  
ll ans=0;
for(int c=1;c<=n-1;c++)
{
  int num=n-c;
  ans+=2*v[num].size();
  if(v[num].back()*v[num].back()==num)
  ans--;
}
cout<<ans;
return ;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test=1;
    //cin>>test;
    for(int i=1;i<=test;i++)
    sol();
}
