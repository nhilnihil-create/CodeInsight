#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<queue>
#include<map>
#include<math.h>

#define ll long long
#define dd double
#define scl(n)        scanf("%lld",&n)
#define scd(n)        scanf("%lf",&n)
#define scc(n)        scanf("%c",&n)
#define scs(n)        scanf("%s",&n)
#define ptl(n)        printf("%lld",n)
#define ptd(n)        printf("%f",n)
#define ptc(n)        printf("%c",n)
#define pts(n)        printf("%s",n)
#define nline         printf("\n")
#define pb            push_back
#define FOR(i,a,b)    for(ll i=a;i<=b;i++)
#define FORr(i,a,b)   for(ll i=a;i<=b;i--)
#define pi            2*acos(0.0)
#define pii           pair<ll,ll>
#define uu            first
#define vv            second
#define m       1000004
using namespace std;
vector<ll>prime,mark(m,0);
void sieve()
{
    prime.pb(2);
    for(ll i=4;i<m;i+=2)
        mark[i]=1;
    for(ll j=3;j<m;j+=2)
    {
        if(!mark[j])
        {
            prime.pb(j);
            for(ll k=j*j;k<m;k+=2*j)
                mark[k]=1;
        }
    }
}
ll a[1000006]={0};
int main()
{
   // sieve();
    ll n,high=-2,i,x;
   // vector<ll>pr;
    scl(n);
    ll g=0;
    FOR(i,1,n)
    {
        scl(x);
        a[x]++;
        if(x>high)
            high=x;
        g=__gcd(g,x);
    }
    if(g!=1)
    {
       printf("not coprime");
       return 0;
    }
    for(ll d=2;d<=high;d++)
    {
        ll cnt=0;
        for(i=d;i<=high;i+=d)
        {
           cnt+=a[i];
        }
        if(cnt>1)
        {
            printf("setwise coprime");
            return 0;
        }
    }
    printf("pairwise coprime");
//    for(i=0;prime[i]<=sqrt(high);i++)
//    {
//        cnt=0;
//        FOR(j,1,n)
//        {
//            if(a[j]%prime[i]==0)
//                cnt++;
//        }
//        if(cnt>1)
//        {
//            goto jump;
//        }
//    }
//    FOR(i,1,n)
//    {
//        if(a[i]>sqrt(high)&&mark[a[i]]==0)
//        {
//            pr.pb(a[i]);
//        }
//    }
//    for(ll i:pr)
//    {
//        cnt=0;
//        FOR(j,1,n)
//        {
//            if(a[j]%i==0)
//                cnt++;
//        }
//        if(cnt>1)
//            goto jump;
//    }
//    printf("pairwise coprime");
//    return 0;
//jump:
//    ll result=__gcd(a[1],a[2]);
//    FOR(i,3,n)
//    {
//        result=__gcd(result,a[i]);
//    }
//    if(result==1)
//        printf("setwise coprime");
//    else
//        printf("not coprime");
    return 0;
}
