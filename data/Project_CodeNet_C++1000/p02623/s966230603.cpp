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
ll b[maxn];
void run_case()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i + 1];
        a[i + 1] += a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i + 1];
        b[i + 1] += b[i];
    }
    int ans = 0;
    // for (int i = 1; i <= m; i++)
    // {
    //     DBG(b[i]);
    // }
    //DBG(b[m]);
    for (int i = 0, j = m; i <= n; i++)
    {
        //  DBG(ans);
        if (a[i] > k)
            break;
        while (a[i] + b[j] > k)
        {
            j--;
            //DBG(j);
        }
        ans = max(i + j, ans);
        //DBG(ans);
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