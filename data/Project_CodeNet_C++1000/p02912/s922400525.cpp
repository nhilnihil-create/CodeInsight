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
const int maxn = 110000;
int main()
{
    //检查有没有特判0,有没有越界限.
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(12);
    int n, m;
    cin >> n >> m;
    priority_queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    while (m--)
    {
        int cur = q.top();
        q.pop();
        cur /= 2;
        q.push(cur);
    }
    ll ans = 0;
    while (!q.empty())
    {
        int cur = q.top();
        q.pop();
        ans += 1ll * cur;
    }
    cout << ans << "\n";
    return 0;
}