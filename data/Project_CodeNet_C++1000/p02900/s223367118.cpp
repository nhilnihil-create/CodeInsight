#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

vector<long long> divisor(long long n)
{
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ret.push_back(n / i);
            if (n != 1)
                ret.push_back(i);
        }
    }
    return ret;
}

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

int main()
{
    ll a, b;
    cin >> a >> b;
    vector<ll> c = divisor(gcd(a, b)), d;
    // for (ll i = 1; i * i <= min(a, b); i++)
    //     if (a % i == 0 && b % i == 0)
    //         c.push_back(i);
    // if (a == b)
    //     c.push_back(a);
    sort(c.begin(), c.end());
    // rep(i, c.size()) cout << c[i] << endl;
    for (ll i = 0; i < c.size(); i++)
    {
        ll flag = 0;
        for (ll j = 0; j < d.size(); j++)
        {
            if (gcd(c[i], d[j]) != 1)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            d.push_back(c[i]);
    }
    // rep(i, d.size()) cout << d[i] << endl;
    cout << d.size() << endl;
    return 0;
}