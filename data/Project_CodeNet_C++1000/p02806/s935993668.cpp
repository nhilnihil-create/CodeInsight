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
    vector<string> s(n);
    vector<int> t(n);
    rep(i, n) cin >> s[i] >> t[i];
    string x;
    cin >> x;
    int ans = 0;
    bool ok = false;
    rep(i, n)
    {
        if (s[i] == x)
        {
            ok = true;
            continue;
        }
        if (ok)
            ans += t[i];
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