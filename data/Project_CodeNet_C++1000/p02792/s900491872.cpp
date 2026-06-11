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
    //检查有没有特判0,有没有越界限.
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(12);
    int n;
    cin >> n;
    int cnt[10][10] = {0};
    for (int i = 1; i <= n; i++)
    {
        int k = i;
        int num1 = k % 10;
        while (true)
        {
            //DBG(i);
            if (k >= 1 && k <= 9)
            {
                //DBG(i);
                break;
            }
            k = k / 10;
        }
        int num2 = k;
        cnt[num2][num1]++;
    }
    ll ans = 0;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            ans += 1ll * cnt[i][j] * cnt[j][i];
            //DBG(ans);
        }
    }
    cout << ans << "\n";
    return 0;
}