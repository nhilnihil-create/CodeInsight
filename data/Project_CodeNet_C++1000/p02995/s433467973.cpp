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

ll num(ll x,ll y,ll d)
{
   return (y/d)-((x-1)/d);
}
int main()
{
   ll a,b,c,d;
   cin>>a>>b>>c>>d;
   ll t=b-a+1;
   ll v=0;
   v+=num(a,b,c);
   v+=num(a,b,d);
   v-=num(a,b,(c*d)/__gcd(c,d));
   ll ans=t-v;
   pf(ans);
}