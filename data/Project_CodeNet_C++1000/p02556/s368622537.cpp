#include <bits/stdc++.h>


#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define el '\n'

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int N = 2e5 + 10;
const ll INF = 1e18;

int n;
pll ar[N];

ll mn1 = INF, mn2 = INF; // x + y, x - y

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> ar[i].fi >> ar[i].se;
    } 
    sort(ar + 1, ar + n + 1);
    ll ans = 0;
    for (int i=1;i<=n;i++){
        ll a = ar[i].fi + ar[i].se;
        ll b = ar[i].fi - ar[i].se;
        ans = max(ans, a - mn1);
        ans = max(ans, b - mn2);
        mn1 = min(mn1, a);
        mn2 = min(mn2, b);
    }
    cout << ans << el;

    return 0;
}