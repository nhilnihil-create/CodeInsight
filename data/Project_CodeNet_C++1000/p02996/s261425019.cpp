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

vector<pi> ar;
bool cmp(pi a,pi b)
{
  return a.s<b.s;
}
int main()
{
   ll n,sum=0;
   sf(n);
   for(ll i=0;i<n;i++)
   {
    ll x,y;
    sf(x),sf(y);
    ar.pb(mp(x,y));
   }
   sort(ar.begin(),ar.end(),cmp);
   for(auto e:ar)
   {
    sum+=e.f;
    if(sum>e.s) 
    {
      printf("No");
      return 0;
    }
   }
   printf("Yes");
}