#include <bits/stdc++.h>

using namespace std;
#define DBG(x)                         \
    (void)(cout << "L" << __LINE__     \
                << ": " << #x << " = " \
                << (x) << '\n')

typedef long long ll;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int maxn = 110000;
int n;
bool check(vector<vector<int>> cnt, int s)
{
    for (int i = 0; i < n; i++)
    {
        if ((s >> i) & 1)
        {
            for (int j = 0; j < n; j++)
            {
                if (cnt[i][j] != -1 && cnt[i][j] != (s >> j & 1))
                    return false;
            }
        }
    }
    return true;
}
int main()
{
    //检查有没有特判0,有没有越界限.
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(12);
    //int n;
    cin >> n;
    //vector<int> cnt(n + 1, 1);
    vector<vector<int>> cnt(n, vector<int>(n, -1));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        //bool ok = 1;
        for (int j = 1; j <= a; j++)
        {
            int x, y;
            cin >> x >> y;
            x--;
            cnt[i][x] = y;
        }
    }
    int num = (1 << n) - 1;
    //cout << "num:" << num << "\n";
    for (int s = 0; s <= num; s++)
    {
        //bool ok = 1;
        if (check(cnt, s))
        {
            ans = max(ans, __builtin_popcount(s));
        }
    }
    cout << ans << "\n";
    return 0;
}