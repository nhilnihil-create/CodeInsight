#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
int D;
ll ans = 0;
vector<int> c(26);
int main()
{
    cin >> D;
    int s[366][28];
    int last[28];
    rep(i, 1, 27)
    {
        cin >> c[i];
    }
    rep(i, 1, D + 1)
    {
        rep(j, 1, 27)
        {
            cin >> s[i][j];
            last[j] = 0;
        }
    }
    vector<int> t(D);
    rep(i, 1, D + 1)
    {
        cin >> t[i];
    }
    rep(i, 1, D + 1)
    {
        rep(j, 1, 27)
        {
            if (t[i] != j)
            {
                ans -= c[j] * (i - last[j]);
                // cout << "ans=" << ans << endl;
            }
        }
        ans += s[i][t[i]];
        last[t[i]] = i;
        cout << ans << endl;
    }
    return 0;
}
