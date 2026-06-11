#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define be begin()
#define en end()
#define SZ(x) ((int)(x).size())
#define le length()
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (ll i = 0; i < n; i++)
#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define c(a) cout << a << "\n";
#define endl '\n'
const int MOD = 1e9 + 7;
const int N = 3e5 + 6;
#define pi 3.141592653589793
// int v[N];
// void add(int idx, int val)
// {
//     while (idx <= N)
//     {
//         v[idx] += val;
//         idx += idx & -idx;
//     }
// }

// int sum(int idx)
// {
//     int ans = 0;
//     while (idx > 0)
//     {
//         ans += v[idx];
//         idx -= idx & -idx;
//     }
//     return ans;
// }
bool check(ll n, ll i)
{
    if (i == 1)
        return false;
    while (n % i == 0)
        n /= i;
    n %= i;
    return n == 1;
}
int main()
{
    ll n;
    cin >> n;
    ll x = n - 1;
    set<ll> s;
    for (ll i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            s.insert(i);
            s.insert(x / i);
        }
    }
    s.insert(x);
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (check(n, i))
                s.insert(i);
            if (check(n, n / i))
                s.insert(n / i);
        }
    }
    if(s.find(1)!=s.end()) s.erase(s.find(1));
    s.insert(n);
    c(s.size())

        return 0;
}