#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#pragma GCC optimize(2)
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const double eps=1e-5;
const double pi=acos(-1.0);
const int MOD=1e9+7;
const int maxn=1e6+10;
ll pow_mod(ll a,ll i,ll n)
{
    if(i==0)
        return 1%n;
    ll temp=pow_mod(a,i>>1,n);
    temp=temp*temp%n;
    if(i&1)
        temp=(ll)temp*a%n;
    return temp;
}
bool test(ll n,ll a,ll d)
{
    if(n==2) return true;
    if(n==a) return true;
    if((n&1)==0) return false;
    while(!(d&1))
        d=d>>1;
    ll t=pow_mod(a,d,n);
    while((d!=n-1)&&(t!=1)&&(t!=n-1))
    {
        t=(ll)t*t%n;
        d=d<<1;
    }
    return (t==n-1||(d&1)==1);
}
bool isprime(ll n)
{
    if(n<2)
        return false;
    ll tt[46]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199};
    for(int i=0;i<=19;i++)
    {
        if(n<tt[i])
            break;
        if(!test(n,tt[i],n-1))
            return false;
    }
    return true;
}
int main ()
{
    ll n;
    scanf("%lld",&n);
    if(isprime(n)){
        printf("%lld\n",n-1);
    }
    else{
        int x=(int)floor(sqrt(n));
        for(int i=0;i<x;i++)
        {
            ll a=x-i;
            ll b=n/a;
            if(a*b==n){
                printf("%lld\n",a+b-2);
                break;
            }
        }
    }
    return 0;
}