
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
#define ll  long long
#define endl '\n'
const ll N=1e5+7;
void solve()
{
  ll n, a,m=0,b=-1, c=0,k=0, i, j,l=1e9+7;
  string s;
  cin>>n;
  ll ar[n+1];
  rep(i,1,n+1)
    {
      cin>>ar[i];
      if(i%2 && ar[i]%2) c++;
    }
    cout<<c<<endl;
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