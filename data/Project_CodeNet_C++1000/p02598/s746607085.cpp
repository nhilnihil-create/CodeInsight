//
//  main.cpp
//  ervb
//
//  Created by Kanak Gautam on 21/04/20.
//  Copyright © 2020 Kanak Gautam. All rights reserved.
//
 
 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#define pb push_back
#define mk make_pair
#define endl "\n"
#define mod 1000000007
using namespace std;
typedef long long int lli;
typedef long double ld;
priority_queue <lli, vector<lli>, greater<lli> > ti;
vector <ld> p[300005],f(200005,0),b(200005,0),a(200005,0);
map <pair<lli,lli>,lli> mp;
set<pair<lli, lli> > s;
set<lli> st;
map<lli,lli> np,v;
queue<lli> q;
lli gcd(lli a, lli b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
      
}
lli bpow(lli a, lli b) {
    lli res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res%mod;
}
/*lli fact(lli i)
{
    f[0]=1;
    for(lli k=1;k<=i;k++)
    {
        (f[k]=f[k-1]*k)%=mod;
    }
    return f[i];
}*/
lli isprime(lli n)
{
    if(n==1)
        return 0;
    for(lli i=2;i<=sqrt(n);i++)
        if(n%i==0)
            return 0;
    return 1;
}
bool cmp(lli i,lli j)
{
    return p[i].size()<p[j].size();
}
 
/*void sieve()
{
    for(lli i=2;i<=5000000;i++)
    {
        if(b[i]==0)
        {
        for(lli j=2;i*j<=5000000;j++)
        {
            b[i*j]=1;
        }
        }
    }
}*/

lli n,k;
bool check(lli x)
{
    lli c=k,j;ld f;
    for(lli i=1;i<=n;i++)
    {
        f=a[i]/x;
        j=ceil(f);
        c-=(j-1);
        //cout<<c<<" "<<j<<endl;
        if(c<0)return false;
    }
    return true;
}
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n>>k;
    ld r=0;
    for(lli i=1;i<=n;i++)
    {
        cin>>a[i];
        r=max(r,a[i]);
    }
    ld l=1;lli ans=r;
    while(l<=r)
    {
        ld mid=(l+r)/2;
        lli x=ceil(mid);
        //cout<<x<<endl;
        if(check(x))
        {
            ans=x;
            r=x-1;
        }
        else l=x+1;
    }
    cout<<ans<<endl;
}
