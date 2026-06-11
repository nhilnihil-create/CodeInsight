#include <bits/stdc++.h>

using namespace std;
#define DBG(x)                         \
    (void)(cout << "L" << __LINE__     \
                << ": " << #x << " = " \
                << (x) << '\n')
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
typedef long long ll;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const long double PI = (acos(-1));
const long double EPS = 0.0000000001;
const int INF = 0x3f3f3f3f;
const int maxn = 1100000;
char mp[10][10];
void run_case()
{
    int H, W, K;
    cin >> H >> W >> K;
    for (int i = 0; i < H; i++)
    {
        cin >> mp[i];
    }
    int len1 = (1 << H) - 1;
    int len2 = (1 << W) - 1;
    // DBG(len1);
    // DBG(len2);
    int ans = 0;
    for (int col = 0; col <= len1; col++)
    {
        //int cnt = 0;
        for (int row = 0; row <= len2; row++)
        {
            int cnt = 0;
            for (int i = 0; i < H; i++)
            {
                for (int j = 0; j < W; j++)
                {
                    char ch = mp[i][j];
                    if (ch == '#' && ((col >> i) & 1) == 0 && ((row >> j) & 1) == 0)
                        cnt++;
                }
            }
            if (cnt == K)
                ans++;
        }
    }
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(12);
    run_case();
    cout.flush();
    return 0;
}