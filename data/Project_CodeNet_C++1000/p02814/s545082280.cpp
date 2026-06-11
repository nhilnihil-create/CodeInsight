#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 最大公約数
ll gcd(ll m, ll n)
{
    if (n == 0)
        return m;
    else
        return gcd(n, m % n);
}

// 最小公倍数
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}
// https://yamakasa.net/atcoder-abc-150-d/
int main()
{
    int N;
    ll M;
    cin >> N >> M;

    ll a[N];
    ll b = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        b = max(b, a[i] / 2);
    }

    ll l = 1;
    for (int i = 0; i < N; i++)
    {
        l = lcm(l, a[i] / 2);
        if (l > M)
        {
            cout << "0\n";
            return 0;
        }
    }

    for (int i = 0; i < N; i++)
    {
        ll t = l / (a[i] / 2);
        if (t % 2 == 0)
        {
            cout << "0\n";
            return 0;
        }
    }

    cout << (M - l) / (2 * l) + 1 << "\n";
    return 0;
}