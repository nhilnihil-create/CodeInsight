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
void solve()
{
  ll n, a,m=0,b=1, k=0, i, j,l=1e9+7;
  string s, r, y;
  cin>>n>>a;
 // ll ar[n+2]={0};
 vector<ll>ar(n+2);
  //ll br[n]={0};
  vector<ll>br(n);
  ar[n]=1;
 // ar[n-1]=1;
  while(a--)
  {
    cin>>m;
    br[m]=1;
  }
  per(i,n-1,-1)
  {
    if(br[i]) continue ;
    ar[i]=(ar[i+1]+ar[i+2])%l;
  }
  cout<<ar[0];
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