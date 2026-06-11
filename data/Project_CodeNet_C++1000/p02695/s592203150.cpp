#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)
typedef long long ll;

int ans = 0;
int n, m, q;
vector<int> a, b, c, d;

void dfs(vector<int> v)
{
    if (v.size() == n)
    {
        int score = 0;
        rep (i, q)
            if (v[b[i] - 1] - v[a[i] - 1] == c[i])
                score += d[i];

        ans = max(score, ans);
        return;
    }

    v.push_back(v.back());
    while (v.back() <= m)
    {
        dfs(v);
        v.back()++;
    }
}

int main()
{
    cin >> n >> m >> q;

    a.resize(q);
    b.resize(q);
    c.resize(q);
    d.resize(q);
    rep (i, q)
        cin >> a[i] >> b[i] >> c[i] >> d[i];

    vector<int> v(1, 1);
    dfs(v);

    cout << ans << endl;
    return 0;
}