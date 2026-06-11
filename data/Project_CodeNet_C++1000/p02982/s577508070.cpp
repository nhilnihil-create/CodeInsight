
#include <bits/stdc++.h>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<string.h>
using namespace std;
#define pb push_back
#define all(v) v. begin(),v. end()
#define  rep(i,n,v) for(i=n;i<v;i++)
#define per(i,n,v) for(i=n;i>v;i--)
#define ff first 
#define ss second 
#define pp pair<ll,ll>
#define eps 1e-6
#define ll  long long
#define endl '\n'
ll a;
bool isInt(long double s)
{
 return fabs(s-floor(s))<=eps;
}
long double dist(vector<long double>&v, vector<long double>&b)
{
  ll i;
  long double di=0;
  rep(i,0,a)
  {
    di+=(fabs(v[i]-b[i]))*(fabs(v[i]-b[i]));
  }
  return sqrtf(di);
}
void solve()
{
  ll n,m=0, k=0, i, j,l=2e9+7;
  string s, r, y;
  cin>>n>>a;
  vector<vector<long double>>v(n,vector<long double>(a));
  rep(i,0,n) rep(j,0,a) cin>>v[i][j];
  rep(i,0,n)
  {
    rep(j,i+1,n)
    {
      long double res=dist(v[i],v[j]);
      if(isInt(res)) k++;
    }
  }
  cout<<k;
}
int main()
{
 ios_base::sync_with_stdio(false);
  cin. tie(0);cout. tie(0);
    ll t=1;
   //cin>>t;
    while(t--)
    {
      solve();
    }
    return 0;
}