#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define go(i, a, n) for (ll i = a; i < (ll)n; i++)
#define gor(i, a, n) for (ll i = (ll)n - 1; i >= 0; i--)
#define gos(i, a, n, step) for (ll i = a; i < (ll)n; i += step)
#define show(a) cout << a << '\n'
#define show2(a, b) cout << a << " " << b << '\n'
#define show3(a, b, c) cout << a << " " << b << " " << c << '\n'
#define show4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << '\n'
#define ull unsigned long long
#define ld long double
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define mod 1000000007
#define all(v) v.begin(), v.end()
#define mem(a, k) memset(a, k, sizeof(a))
#define answer(z, k) cout << "Case #" << z << ": " << k << endl;
#define ans(z) cout << "Case #" << z << ": "
auto t1 = chrono::high_resolution_clock::now();
ll count(ll s, vector<ll> &dp)
{
    if (!s)
        return 1;
    if (s < 0)
        return 0;
    if (dp[s] != 0)
        return dp[s];
    ll cnt = 0;
    go(i, 3, s + 1) cnt = ((cnt % mod) + (count(s - i, dp) % mod)) % mod;
    return dp[s] = cnt % mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // ll t;
    // cin >> t;
    // while (t--)
    // {
    // }
    ll s;
    cin >> s;
    vector<ll> dp(s + 1, 0);
    show(count(s, dp));
    auto t2 = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(t2 - t1).count();
    clog << "Time taken = " << duration * 1.0 / 1000 << " seconds" << endl;
    return 0;
}
