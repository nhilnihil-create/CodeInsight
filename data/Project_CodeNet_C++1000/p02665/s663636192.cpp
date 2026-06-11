#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

ll a[100010];

int main(){
    int n;
    cin >> n;
    rep(i, n+1) cin >> a[i];
    bool flag = true;

    if (a[0] != 0) flag = false;
    if (a[0] == 1 && n == 0) flag = true;

    ll y = 0;
    rep(i, n+1) y += a[i];

    y -= 1;
    ll cnt = 0;
    ll now = 1;

    rep(i, n){
        // cout << now << " " << y << endl;
        cnt += now;

        if (now < a[i]) flag = false;
        now -= a[i];
        ll tmp = min(y, now);
        now += tmp;
        y -= tmp;
    }

    // cout << now << " " << y << endl;


    if (now != a[n]) flag = false;
    else cnt += a[n];

    if (flag) cout << cnt << endl;
    else cout << -1 << endl;

    return 0;
}
