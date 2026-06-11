#include <bits/stdc++.h>
//#include <random>
//#include <chrono>
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define repk(i,m,n) for(int i=m;i<n;i++)
#define MotoHaiyaku ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pll;
//mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MOD1=1e9+7;
const int MOD2=998244353;
const ll INF=2*1e18;
const ld PI=3.14159265358979323846;
int main()
{
    MotoHaiyaku
   ll n,k;
   cin>>n>>k;
   vector<ll> a(n);
   rep(i,n) cin>>a[i];
   ll l=1,r=1e9;
   while(r>l)
   {
       ll m=(l+r)/2,cur=0;
       rep(i,n) cur+=(a[i]+m-1)/m-1;
       if(cur<=k) r=m;
       else l=m+1;
   }
   cout<<l;
}
