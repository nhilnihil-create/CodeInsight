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

ll val[10000002];
int main()
{
 ll n,ans=0;
 sf(n);
 for(ll i=1;i<=n;i++)
 {
 	for(ll j=i+i;j<=n;j+=i)
 		val[j]++;
 }
 for(ll i=1;i<=n;i++)
 	ans+=(val[i]+1)*i;
 pf(ans);
}
