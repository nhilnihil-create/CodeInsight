#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
const int maxn=1e6+10;
const int mod=1e9+7;
const double pi=3.1415926535;

ll fac[maxn];
ll inv[maxn];
ll power(ll base, ll n)
{
    ll r=1;
    while(n)
    {
        if(n%2) r=r*base%mod;
        base=base*base%mod;
        n/=2;
    }
    return r;
}

void init()
{
    fac[0]=1;
    for(int i=1;i<maxn;i++)
    {
        fac[i]=fac[i-1]*i%mod;
    }
    inv[maxn-1]=power(fac[maxn-1],mod-2);
    for(int i=maxn-2;i>=0;i--)
    {
        inv[i]=inv[i+1]*(i+1)%mod;
    }
}
ll C(ll m,ll n)
{
    return fac[n]*inv[m]%mod*inv[n-m]%mod;

}




int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    int x,y;
    cin>>x>>y;
    int cntx=0;
    int cntxy=0;
    int f=0;
    for(int i=1;i<maxn;i++)
    {
        if(y%2==0&&x==y/2)
        {
            cntxy+=cntx+x;
            f=1;
            break;
        }
        if(x<2||y<1)
            break;
        cntx++;
        x-=2;
        y--;

    }
    //cout<<cntx<<" "<<cntxy<<'\n';
    if(f==0)
        cout<<0<<'\n';
    else
        cout<<C(cntx,cntxy)<<'\n';









}
