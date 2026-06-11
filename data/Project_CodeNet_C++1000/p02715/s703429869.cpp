#include <bits/stdc++.h>
#define _for(i,a,b) for(int i=(a),_b=(b);i<_b;++i)

using namespace std;
const int maxn = 100001;
typedef long long ll;
const ll mod  = 1e9 + 7;
ll f[maxn];
int n,k;
vector<int> d[maxn];
void _sieve()
{
    for(int i = 2; i<maxn; ++i)
        for(int j = i ; j<maxn; j+=i)
            d[j].push_back(i);
}
ll _pow(ll A,ll B)
{
    if (B==0) return ll(1);
    ll p  = _pow(A, B/2);
    p = p*p;
    p = p%mod;
    return (B%2==0) ? p : ((A*p)%mod);
}
void solve()
{
    for(int i = k;i>=1; --i)
    {
        f[i] = f[i] + _pow( k /i , n);
        f[i] = f[i]%mod;
        for(int j = i+ i;j<=k; j+=i)
        {
            f[i] -= f[j];
            f[i] = f[i] + mod;
            f[i] = f[i] %mod;
        }
    }
    ll ans = 0;
    _for(i,1,k+1)
    {
        ans = ans + f[i]*ll(i);
        ans = ans%mod;
    }
    cout<<ans;
}
int main()
{
    cin>>n>>k;
    solve();
}
