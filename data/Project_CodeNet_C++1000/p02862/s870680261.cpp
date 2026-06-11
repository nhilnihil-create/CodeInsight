#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
using ll=long long;
ll factorial[2000000];

ll power(ll n,ll m)
{
    ll ans=1;
    for (int r=0;m>>r>0;r++)
    {
        if ((m>>r)&1) ans=ans*n%mod;
        n=n*n%mod;
    }
    return ans;
}

ll inv(ll n)
{
    return power(n,mod-2);
}

void fact()
{
    factorial[0]=1;
    for (int i=1;i<2000000;i++) factorial[i]=i*factorial[i-1]%mod;
    return;
}

ll cmb(ll n,ll r)
{
    if (r>n) return 0;
    else return factorial[n]*inv(factorial[n-r])%mod*inv(factorial[r])%mod;
}

int main()
{
    fact();
    ll X,Y;cin >> X >>Y;
    ll x=(2*X-Y)/3,y=(2*Y-X)/3;
    if ((2*X-Y)%3!=0 || (2*Y-X)%3!=0 || x<0 || y<0)
    {
        cout << 0 <<endl;
        return 0;
    }
    else
    {
        cout << cmb(x+y,x) <<endl;
        return 0;
    }
}
