#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
inline void normal(ll &a)
{
    a %= MOD;
    (a < 0) && (a += MOD);
}
inline ll modMul(ll a, ll b)
{
    a %= MOD, b %= MOD;
    normal(a), normal(b);
    return (a*b)%MOD;
}
inline ll modAdd(ll a, ll b)
{
    a %= MOD, b %= MOD;
    normal(a), normal(b);
    return (a+b)%MOD;
}
inline ll modSub(ll a, ll b)
{
    a %= MOD, b %= MOD;
    normal(a), normal(b);
    a -= b;
    normal(a);
    return a;
}
inline ll modPow(ll b, ll p)
{
    ll r = 1;
    while(p)
    {
        if(p&1)
            r = modMul(r, b);
        b = modMul(b, b);
        p >>= 1;
    }
    return r;
}

inline ll modInverse(ll a)
{
    return modPow(a, MOD-2);
}
inline ll modDiv(ll a, ll b)
{
    return modMul(a, modInverse(b));
}

map<int,int>cnt;



main()
{

    ll n,k,ans;
    cin>>n>>k;
    cnt[k]=1;
    ans=k;
    for(int i=k-1; i>=1; --i)
    {
        int rp=k/i;
        cnt[i]=modPow(rp,n);
        for(int j=i+i; j<=k; j+=i)
        {
            cnt[i]=cnt[i]+MOD-cnt[j];
            if(cnt[i]>=MOD)
                cnt[i] -= MOD;
        }
        ans += 1LL * cnt[i] * i;
        ans %= MOD;
    }

    cout<<ans<<endl;


}
