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
#define ll  long long
#define endl '\n'
void solve()
{
  ll n, a,m=0,b=1, c,k=0, i, j,l=1e9+7;
  string s, r, y;
  cin>>s;
  n=s.length();
   vector<ll>v(n+1,0);
   ll rig=0,lef=0;
   rep(i,0,n)
   {
     if(s[i]=='<') rig++;
     else rig=0;
     v[i+1]=rig;
   }
   per(i,n-1,-1)
   {
     if(s[i]=='>') lef++;
     else lef=0;
    v[i]=max(v[i],lef);
   }
   rep(i,0,n+1) k+=v[i];
   cout<<k;
}
int main()
{
 ios_base::sync_with_stdio(false);
  cin. tie(0);cout. tie(0);
    ll t=1;
 //  cin>>t;
    while(t--)
    {
      solve();
    }
    return 0;
}