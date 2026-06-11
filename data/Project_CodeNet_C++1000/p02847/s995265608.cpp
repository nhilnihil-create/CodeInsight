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
  if(s=="SUN") cout<<7;
  else if(s=="MON") cout<<6;
  else if(s=="TUE") cout<<5;
  else if(s=="WED") cout<<4;
  else if(s=="THU") cout<<3;
  else if(s=="FRI") cout<<2;
  else cout<<1;
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
