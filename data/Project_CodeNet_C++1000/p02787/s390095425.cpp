#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

const int MAXH { 10010 }, MAXN { 1010 };
const ll MOD { 1000000007 }, oo { 1LL << 35 };

ll st[MAXH][MAXN];

ll dp(int h, int i, int N, const vector<ii>& xs)
{
    if (h <= 0)
        return 0;

    if (i == N)
        return h < 0 ? 0 : oo; 

    if (st[h][i] != -1)
        return st[h][i];

    ll res = dp(h, i + 1, N, xs);

    if (h > 0)
    {
        res = min(res, dp(h - xs[i].first, i, N, xs) + xs[i].second);
        res = min(res, dp(h - xs[i].first, i + 1, N, xs) + xs[i].second);
    }

    st[h][i] = res;
    return res;
}

ll solve(int H, int N, const vector<ii>& xs)
{
    memset(st, -1, sizeof st);

    return dp(H, 0, N, xs);
}

int main()
{
    ios::sync_with_stdio(false);

    int H, N;
    cin >> H >> N;

    vector<ii> xs(N);

    for (int i = 0; i < N; ++i)
        cin >> xs[i].first >> xs[i].second;

    auto ans = solve(H, N, xs);

    cout << ans << '\n';

    return 0;
}
