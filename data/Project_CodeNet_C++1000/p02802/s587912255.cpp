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
bool isPrime(ll a)
{
  ll count=0,i;
  rep(i,2,a/2+1)
    if(a%i==0) count++;
    if(count) return false;
    else return true;
}
void solve()
{
  ll n, a,m=0,b=1, k=0, i, j,l=2e9+7;
  string s, r, y;
  cin>>n>>a;
  ll ar[n+1]={0},br[n+1]={0};
 while(a--)
 {
   cin>>n>>s;
   if(ar[n]==0 && s=="WA")
   br[n]++;
   else if(ar[n]==0 && s=="AC")
   {
     ar[n]=1;k++;m+=br[n];
   }
 }
 cout<<k<<" "<<m;
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