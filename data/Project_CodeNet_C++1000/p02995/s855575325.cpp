#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i < n; i++)
using P = pair<ll, ll>;


ll gcd(ll m, ll n)
{
    if (m < n)
    {
        ll tmp = m;
        m = n;
        n = tmp;
    }

    while (1)
    {
        ll mod = m % n;
        if (mod == 0)
            return n;
        m = n;
        n = mod;
    }
}
ll lcm(ll m, ll n)
{
    return m * n / gcd(m, n);
}

int main()
{
    ll a, b, c, d, ans;
    cin >> a >> b >> c >> d;
    a--;
    ans = b - a;
    b = b / c + b / d - b / lcm(c, d);
    a = a / c + a / d - a / lcm(c, d);
    ans-=b-a;
    cout<<ans<<endl;
    return 0;
}