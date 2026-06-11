#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = (ll)(1e9 + 7);
int main()
{
    ll n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    ll sum = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] > a[j])
                sum++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                sum2++;
        }
    }
    ll cnt = 0;
    ll cntkmin1 = (k * (k - 1) / 2) % MOD;
    ll cntkmin2 = k % MOD;
    cnt = (sum2 * k % MOD + sum * cntkmin1 % MOD);
    cout << cnt % MOD << endl;
}
