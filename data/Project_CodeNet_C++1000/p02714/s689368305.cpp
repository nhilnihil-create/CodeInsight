#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<int>> sum(n + 1);
    rep(i, n + 1) sum[i].assign(3, 0);

    sum[0][0] = sum[0][1] = sum[0][2] = 0;

    for (int i = 0; i < n; ++i)
    {
        rep(j, 3) sum[i + 1][j] = sum[i][j];
        if (s[i] == 'R')
            ++sum[i + 1][0];
        else if (s[i] == 'G')
            ++sum[i + 1][1];
        else
            ++sum[i + 1][2];
    }

    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        char t = s[i];
        if (t == 'R')
            ans += (sum[n][1] - sum[i][1]) * (sum[n][2] - sum[i][2]);
        else if (t == 'G')
            ans += (sum[n][0] - sum[i][0]) * (sum[n][2] - sum[i][2]);
        else
            ans += (sum[n][1] - sum[i][1]) * (sum[n][0] - sum[i][0]);
        const int g = n - i;

        for (int j = 1; 2 * j < g; ++j)
        {
            if (s[i + j] != t && s[i + 2 * j] != t && s[i + j] != s[i + 2 * j])
                --ans;
        }
    }

    cout << ans << endl;
}