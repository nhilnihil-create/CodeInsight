#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define repr(i, n) for (ll i = n - 1; i >= 0; --i)
#define INF 10e7
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))
using namespace std;

void solve(void)
{
    string s;
    cin >> s;
    int len = s.length();
    vector<pair<int, int>> vp;
    vector<int> vi, ans(len);
    int r = 0, l = 0, m;
    rep(i, len)
    {
        if (s[i] == 'R')
            r++;
        if (s[i] == 'L')
            l++;
        if (s[i] == 'R' && s[i + 1] == 'L')
            m = i;
        if (s[i] == 'L' && s[i + 1] == 'R' || i == len - 1)
            vp.push_back({r, l}), vi.push_back(m), r = 0, l = 0;
    }
    rep(i, vi.size())
    {
        ans[vi[i] + 1] = vp[i].first / 2 + (vp[i].second + 1) / 2;
        ans[vi[i]] = (vp[i].first + 1) / 2 + vp[i].second / 2;
    }
    rep(i, len) cout << ans[i] << " ";
    cout << endl;
}
int main(void)
{
    solve();
}