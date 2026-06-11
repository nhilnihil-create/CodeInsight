#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define ll long long
#define ull unsigned long long
#define si set <ll>
#define vi vector <ll>
#define popcount(x) __builtin_popcountll(x)
#define mii map <ll,ll>
#define vpi vector <pair <ll,ll> >
#define sz(c) (int)c.size()
#define fr first
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define sc second
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define mem0(a) memset(a,0,sizeof(a))
#define rep(i,a,n) for( ll i=a ; i<n ; i++)
#define ld long double
#define rall(a) (a).rbegin(),(a).rend()

ll power(ll b,ll e,ll m)
{
  if(e==0) return 1;
  if(e&1) return b*power(b*b%m,e/2,m)%m;
  return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
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
  ll a,b,c,k;
  cin>>a>>b>>c>>k;
  int x=0,y=0;
  while(b<=a) 
  {
    b*=2;
    x++;
  }
  while(c<=b) 
  {
    c*=2;
    y++;
  }
  if(x+y<=k) cout<<"Yes"<<"\n";
  else cout<<"No"<<"\n";
}

int main()       
{
  fastio
  ll tt=1;
  while(tt--)
  {
    solve();
    cout<<"\n";
  }
  return 0;
}