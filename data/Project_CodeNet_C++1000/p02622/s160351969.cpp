#include <bits/stdc++.h>

#define debug(s) cout << s << endl
#define debug1(s, t) cout << s << " " << t << endl
#define debug2(s, t, u) cout << s << " " << t << " " << u << endl
#define printvec(v)       \
    for (auto &&i : v)    \
        cout << i << " "; \
    cout << endl
#define rep(n, i) for (int i = 0; i < n; i++)

using namespace std;
using i64 = long long;

int main()
{
    string s, t;
    cin >> s >> t;

    int n = s.size();

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i])
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}