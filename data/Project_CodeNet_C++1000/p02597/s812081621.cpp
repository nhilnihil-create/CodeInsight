#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    sort(t.begin(), t.end());
    int cnt = 0;
    rep(i, n)
    {
        if (s[i] != t[i])
            cnt++;
    }
    int ans = cnt / 2;
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}