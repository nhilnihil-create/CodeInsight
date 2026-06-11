#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int MOD = 1000000007;

int main()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    rep (i, n)
        cin >> a[i];

    ll ans = 0;
    rep (digit, 60)
    {
        ll cnt0 = 0, cnt1 = 0;
        rep (i, n)
        {
            if (1 & (a[i] >> digit))
                cnt1++;
            else
                cnt0++;
        }
        ll pow = (1LL << digit) % MOD;
        ll temp = cnt0 * cnt1 % MOD;
        temp = temp * pow % MOD;
        ans = (ans + temp) % MOD;
    }

    cout << ans << endl;
    return 0;
}