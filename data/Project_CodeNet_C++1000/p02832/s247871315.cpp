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
const int maxn = 210000;
int a[maxn];
int main()
{
    //检查有没有特判0,有没有越界限.
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(12);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int cur = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == cur)
        {
            cur++;
        }
    }
    if (cur == 1)
        cout << -1 << "\n";
    else
        cout << n - cur + 1 << "\n";
    return 0;
}