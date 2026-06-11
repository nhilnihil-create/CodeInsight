#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
    string s;
    cin >> s;

    int n = s.size();
    vector<ll> sum(n + 1);
    sum[0] = 0;
    ll pow = 1;
    for (int i = 1; i <= n; i++, pow = (pow * 10) % 2019)
        sum[i] = ((s[(n - 1) - (i - 1)] - '0') * pow + sum[i - 1]) % 2019;

    vector<ll> cnt(2019, 0);
    rep (i, n + 1)
        cnt[sum[i]]++;

    ll ans = 0;
    rep (i, 2019)
        ans += cnt[i] * (cnt[i] - 1) / 2;

    cout << ans << endl;
    return 0;
}