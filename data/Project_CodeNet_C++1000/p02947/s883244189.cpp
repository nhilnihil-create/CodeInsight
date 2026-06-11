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
  cin>>n;
  vector<string>v;
  map<string,int>mp;
  rep(i,0,n) {cin>>s;
  sort(s.begin(),s. end());
  //v.pb(s);
  if(mp.find(s)==mp. end())
  mp[s]=1;
  else mp[s]++;
  }
  sort(all(v));
 /* rep(i,0,v.size())
  {
   /* rep(j,i+1,v.size())
    {
      string r=v[i],y=v[j];
      sort(r.begin(),r. end());
      sort(y.begin(),y. end());
      if(r==y) k++;
    }*/
    /*  rep(j,i+1,v.size())
      {
        if(v[i]==v[j]) k++;
      }
  }*/
    for(auto& it : mp) {m=it.ss;k+=(m*(m-1))/2;}
  cout<<k;
}
int main()
{
 ios_base::sync_with_stdio(false);
  cin. tie(0);cout. tie(0);
    ll t=1;
  // cin>>t;
    while(t--)
    {
      solve();
    }
    return 0;
}