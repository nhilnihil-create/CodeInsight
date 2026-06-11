#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int n, m, q;
vector<int> a, b, c, d;

int ans;
void dfs(vector<int> tmp)
{
    if (tmp.size() == n + 1)
    {
        int cnt = 0;
        rep(i, q)
        {
            if (tmp[b[i]] - tmp[a[i]] == c[i])
            {
                cnt += d[i];
            }
        }
        ans = max(ans, cnt);
        return;
    }

    tmp.push_back(tmp.back());
    while (tmp.back() < m + 1)
    {
        dfs(tmp);
        tmp.back()++;
    }
    // int last = tmp.back();
    // for (int i = last; i < m + 1; i++)
    // {
    //     vector<int> tt = tmp;
    //     tt.push_back(i);
    //     dfs(tt);
    // }
}

int main()
{
    cin >> n >> m >> q;
    a = b = c = d = vector<int>(q);
    rep(i, q) cin >> a[i] >> b[i] >> c[i] >> d[i];

    vector<int> tmp(1, 1);
    dfs(tmp);
    cout << ans << '\n';
    return 0;
}
