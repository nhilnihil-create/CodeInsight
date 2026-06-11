#include <map>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <math.h>
#include <iostream>
#include <queue>
#include <set>
#define ll long long
#define sf(a) scanf("%lld",&a)
#define pf(b) printf("%lld",b)
#define sp printf(" ")
#define nw printf("\n")
#define mp make_pair
#define pi pair<ll,ll>
#define f first
#define s second
#define pb push_back
#define sor(v) sort(v.begin(),v.end())
#define rev(v) reverse(v.begin(),v.end())
#define fast ios_base::sync_with_stdio(false)
using namespace std;

ll c[300009],r[300009];
vector<ll> all[300009];
int main()
{
  ll n,m,k;
  cin>>n>>m>>k;
  ll maxc,ans,x,y,cmax;
  ans=maxc=cmax=0;
  for(ll i=0;i<k;i++)
  {
    cin>>x>>y;
    r[x]++;
    c[y]++;
    all[x].pb(y);
  }
  for(ll i=1;i<=m;i++)
    maxc=max(maxc,c[i]);
  for(ll i=1;i<=m;i++)
    if(c[i]==maxc) cmax++;
  for(ll i=1;i<=n;i++){
    ll val=r[i]+maxc;
    ll cc=0;
    for(auto e:all[i]) if(c[e]==maxc) cc++;
    if(cc==cmax) val--;
    ans=max(ans,val);
  }
  cout<<ans;
}
