#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> ans(n, -1);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (a == 1 && b == 0 && n != 1)
        {
            cout << -1 << endl;
            return 0;
        }
        if (ans[a - 1] == -1)
        {
            ans[a - 1] = b;
        }
        else if (ans[a - 1] != b)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    if (ans[0] == -1)
        ans[0] = (n == 1) ? 0 : 1;

    rep(i, n) cout << max(ans[i], 0);
    cout << endl;
}