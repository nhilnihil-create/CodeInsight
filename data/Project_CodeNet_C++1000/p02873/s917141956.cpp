#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int, int>;
using ll = long long;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n + 1);
    rep(i, n)
    {
        if (s[i] == '<')
        {
            a[i + 1] = max(a[i + 1], a[i] + 1);
        }
    }
    for (int i = n; i >= 1; i--)
    {
        if (s[i - 1] == '>')
        {
            a[i - 1] = max(a[i - 1], a[i] + 1);
        }
    }
    ll ans = 0;
    rep(i, n + 1) ans += a[i];
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}