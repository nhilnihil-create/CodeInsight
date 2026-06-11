#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long int
#define ull unsigned long long
#define si set <ll>
#define vi vector <ll>
#define popcount(x) __builtin_popcountll(x)
#define mii map <ll,ll>
#define vpi vector <pair <ll,ll> >
#define sz(c) (ll)c.size()
#define fr first
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sc second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define mem0(a) memset(a,0,sizeof(a))
#define rep(i,a,n) for(ll i=a ; i<n ; i++)
#define ld long double
const ll INF = __LONG_LONG_MAX__;
#define rall(a) (a).rbegin(),(a).rend()
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

ll power(ll b,ll e,ll m)
{
  if(b==0) return 0;
  if(e==0) return 1;
  if(e&1) return b*power(b*b%m,e/2,m)%m;
  return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
  if(b==0) return 0;
  if(e==0) return 1;
  if(e&1) return b*power(b*b,e/2);
  return power(b*b,e/2);
}  
bool isPowerOfTwo(ll x)
{
    // x will check if x == 0 and !(x & (x - 1)) will check if x is a power of 2 or not
    return (x && !(x & (x - 1)));
}

void solve()
{
 string s,t,p;
 cin>>s;
 int n=s.size();
 // cout<<n<<"\n";
 t=s.substr(0,n/2);
 p=s.substr((n+1)/2,n/2);
 reverse(all(p));
 int ans=0;
 int i;
 // cout<<t<<" "<<p<<"\n";
 rep(i,0,n/2)
 {
  if(t[i]!=p[i])
    ans++;
  }
  cout<<ans;
}

int main()
{
  fastio
  ll tt=1;
  // cin>>tt;
  while(tt--)
  {
      solve();
      cout<<"\n";
  }
}