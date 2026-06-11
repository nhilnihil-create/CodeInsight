#include <bits/stdc++.h>

using namespace std;
#define DBG(x)                         \
    (void)(cout << "L" << __LINE__     \
                << ": " << #x << " = " \
                << (x) << '\n')
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 110000;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(12);
    int n, p;
    string s;
    cin >> n >> p;
    cin >> s;
    ll ans = 0;
    if (p == 2)
    {
        for (int i = 0; i < n; i++)
        {
            if ((s[i] - '0') % 2 == 0)
                ans += 1ll * (i + 1);
        }
    }
    else if (p == 5)
    {
        for (int i = 0; i < n; i++)
        {
            if ((s[i] - '0') % 5 == 0)
                ans += 1ll * (i + 1);
        }
    }
    else
    {
        map<int, int> mp;
        int p1 = 1;
        mp[0]++;
        int t = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            t = (t + (s[i] - '0') * p1) % p;
            ans += 1ll * mp[t];
            mp[t]++;
            p1 = p1 * 10 % p;
        }
    }
    cout << ans << "\n";
    return 0;
}
