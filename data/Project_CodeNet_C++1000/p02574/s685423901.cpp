#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define mod 1000000007LL
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res + m) * ( a + m) % m;
        a = a * a % m;
        b >>= 1;
    }
    return (res + m) % m;
}

long long mul(long long a, long long b){
    a = (a + mod) % mod;
    b = (b + mod) % mod;
    return ((a + mod) * (b + mod))%mod;
}
long long add(long long a, long long b){
    a += mod;
    b += mod;
    return (a + b)%mod;
}
ll inv(ll x){
    return binpow(x, mod - 2, mod);
}
ll fun(ll n)
{
    if(n == 0 || n == 1)
        return 0;
    //vector<ll> a(n);
    vector<ll> p(n), s(n);
    p[0] = 1;
    s[n - 1] = n;
    for (ll i = 1; i < n;i++)
    {
        p[i] = p[i - 1] + i + 1;
        s[n - i - 1] = s[n - i] + n - i;
    }
    ll ans = 0;
    // for(auto i: p)
    //     cout << i << " ";
    // cout << endl;
    // for(auto i: s)
    //     cout << i << " ";
    // cout << endl;
    for (ll i = 1; i < n  ;i++)
    {
        ll diff = s[i] - p[i - 1];
        if(diff < 0)
            break;
        if(diff % 2)
            continue;
        diff = diff / 2;
        if(diff + 1 > n)
            continue;
        if(diff == 0)
        {
            if(i > 1)
            ans += (i * (i - 1)) / 2;
            if(n - i > 1)
            ans += ((n - i) * (n - i - 1)) / 2;
        }else
        {
            //cout << " i = " << i << " diff =  " << diff << endl;
            ans += min(diff, min(i, n - i));
        }
    }
    return ans;
}ll f[1000010] = {0};
signed main()
{
    // freopen("output.txt", "w",stdout);
    // ll t;cin>>t;
    // while(t--)
    // {
    //     ll n;
    //     cin >> n;
    //     for (ll i = 1; i <= n;i++)
    //         cout << fun(i) << endl;
    // }
    ll n;cin>>n;
    vector<ll>a(n);
    for(auto &i: a)
        cin >> i;
    
    ll gcd = a[0];
    for(auto it: a)
        f[it]++, gcd = __gcd(it, gcd);
    
    if(gcd > 1)
    {
        cout << "not coprime";
        return 0;
    }
    for (ll i = 2; i <= 1000000;i++)
    {
        ll cnt = 0;
        for (ll j = i; j <= 1000000;j+=i)
        {
            cnt += f[j];
        }
        if(cnt > 1){
            cout<<"setwise coprime";
            return 0;
        }
    }
    cout << "pairwise coprime";
    return 0;
}