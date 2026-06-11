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
  cin>>n>>s;
  if(n%2) {cout<<"No";return;}
  sort(s.begin(),s. end());
  rep(i,0,s.length())
  {
    if(s[i]==s[i+1] && i+1<n){i++;continue ;}
    else if(i+1<n)
    {
      cout<<"No";return;
    }
  }
  cout<<"Yes";
  
// cout<<n*n;
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