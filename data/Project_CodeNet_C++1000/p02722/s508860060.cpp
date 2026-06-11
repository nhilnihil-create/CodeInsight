#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ll n;
    cin >> n;
    set<ll> a;
    ll k = n - 1;
    if(k != 1)
    a.insert(k);
    for (ll i = 2; i * i <= k; i++)
    {
        if (k % i == 0)
        {
            a.insert(k / i);
            a.insert(i);
        }
    }
    set<ll> b;
    b.insert(n);
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            b.insert(n / i);
            b.insert(i);
        }
    }
    ll cnt = 0;
    for (auto v : b)
    {
        ll nn = n;
        while (nn % v == 0)
        {
            nn /= v;
        }
        if (nn % v != 1)
            cnt++;
    }
    cout << a.size() + b.size() - cnt << endl;
}