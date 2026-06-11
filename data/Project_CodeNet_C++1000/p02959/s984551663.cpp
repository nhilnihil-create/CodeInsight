// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
// #include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
// using namespace atcoder;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n);
    rep(i, n + 1) cin >> a[i];
    rep(i, n) cin >> b[i];
    ll ans = 0;
    rep(i, n)
    {
        ans += min(a[i], b[i]);
        b[i] -= min(a[i], b[i]);
        if (b[i] < 0)
            continue;
        ans += min(a[i + 1], b[i]);
        a[i + 1] -= min(a[i + 1], b[i]);
    }
    cout << ans << endl;
}

int main()
{
    // srand((unsigned)time(NULL));
    // int t = clock();
    solve();
    // double et = 1.0 * (clock() - t) / CLOCKS_PER_SEC;
    // printf("Execution Time: %.4lf sec\n", et);
    return 0;
}