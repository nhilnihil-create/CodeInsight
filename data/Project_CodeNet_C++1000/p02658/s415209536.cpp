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
ll a[maxn];
void run_case()
{
    int n;
    cin >> n;
    bool ok = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == 0)
            ok = 0;
    }
    if (!ok)
    {
        cout << 0 << "\n";
        return;
    }
    ll now = 1;
    ll num = 1e18;
    for (int i = 1; i <= n; i++)
    {
        //C;
        //DBG(now);
        if (now > num / a[i])
        {
            //ok = 0;
            cout << -1 << "\n";
            return;
        }
        now *= a[i];
    }
    cout << now << "\n";
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