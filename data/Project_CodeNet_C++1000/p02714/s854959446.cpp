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
    string s;
    cin >> s;
    ll ans = 0;
    int r = 0, g = 0, b = 0;
    rep(i, n)
    {
        if (s[i] == 'R')
            r++;
        if (s[i] == 'G')
            g++;
        if (s[i] == 'B')
            b++;
    }
    ans += (ll)r * g * b;
    int cnt = 0;
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1;; j++)
        {
            if (i - j < 0 || n <= i + j)
                break;
            if (s[i - j] == 'R' && s[i] == 'G' && s[i + j] == 'B')
                cnt++;
            if (s[i - j] == 'R' && s[i] == 'B' && s[i + j] == 'G')
                cnt++;
            if (s[i - j] == 'B' && s[i] == 'G' && s[i + j] == 'R')
                cnt++;
            if (s[i - j] == 'B' && s[i] == 'R' && s[i + j] == 'G')
                cnt++;
            if (s[i - j] == 'G' && s[i] == 'R' && s[i + j] == 'B')
                cnt++;
            if (s[i - j] == 'G' && s[i] == 'B' && s[i + j] == 'R')
                cnt++;
        }
    }
    ans -= cnt;
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