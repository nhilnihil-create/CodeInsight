#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

vector<vector<int>> x;
vector<vector<int>> y;

int main()
{
    int n;
    cin >> n;
    x.resize(n);
    y.resize(n);
    rep(i, n)
    {
        int a;
        cin >> a;
        x[i].resize(a);
        y[i].resize(a);
        rep(j, a)
        {
            cin >> x[i][j] >> y[i][j];
            --x[i][j]; // index 整理
        }
    }

    int ans = 0;
    // 正直者がbit立ってる
    for (int bit = 0; bit < (1 << n); ++bit)
    {
        bool is_ok = true;
        int count = 0;
        rep(i, n)
        {
            if (bit & (1 << i))
            {
                bool honest = true;
                rep(j, (int)x[i].size())
                {
                    if (bit & (1 << x[i][j]) && y[i][j])
                        continue;
                    if (!(bit & (1 << x[i][j])) && !(y[i][j]))
                        continue;
                    honest = false;
                    break;
                }
                if (honest)
                    ++count;
                else
                    is_ok = false;
            }
        }
        if (is_ok)
            ans = max(ans, count);
    }

    cout << ans << endl;
}