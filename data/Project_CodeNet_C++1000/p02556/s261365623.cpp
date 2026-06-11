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
void run_case()
{
    int n;
    cin >> n;
    int mx1 = -INF, mx2 = -INF;
    int mn1 = INF, mn2 = INF;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        int z = x + y;
        mx1 = max(z, mx1);
        mn1 = min(z, mn1);
        int w = x - y;
        mx2 = max(w, mx2);
        mn2 = min(w, mn2);
    }
    int ans = max(mx1 - mn1, mx2 - mn2);
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
