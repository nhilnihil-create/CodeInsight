#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MOD 1000000007

int main()
{
    ll n, k;
    cin >> n >> k;

    ll ans = 0;
    for (ll i = k; i <= n + 1; i++)
    {
        ll min, max;
        min = i * (i - 1) / 2;
        max = (i * (2 * (n - i + 1) + (i - 1))) / 2;
        ans = (ans + (max - min + 1)) % MOD;
    }

    cout << ans << endl;
    return 0;
}