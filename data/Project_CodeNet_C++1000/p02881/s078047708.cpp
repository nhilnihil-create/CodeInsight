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
int main()
{
    //检查有没有特判0,有没有越界限.
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(12);
    ll N;
    cin >> N;
    ll ans = 1e18;
    for (ll i = 1; i * i <= N; i++)
    {
        if (N % i == 0)
        {
            ans = min(ans, i + N / i - 2);
        }
    }
    cout << ans << "\n";
    return 0;
}