#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

template <class T> inline bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <class T> inline bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int n, a[500], b[500], sum, k, ans;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> k;
    rep(i, n) cin >> a[i], sum += a[i];
    for(int i = 1; i * i <= sum; i++) {
        if(sum % i) continue;

        int x = 0;
        rep(j, n) {
            b[j] = a[j] % i;
            x += b[j];
        }
        sort(b, b + n);
        x /= i;
        int s = 0;
        rep(j, n - x) s += b[j];
        if(s <= k) chmax(ans, i);

        int i2 = sum / i;
        x = 0;
        rep(j, n) {
            b[j] = a[j] % i2;
            x += b[j];
        }
        sort(b, b + n);
        x /= i2;
        s = 0;
        rep(j, n - x) s += b[j];
        if(s <= k) chmax(ans, i2);
    }

    cout << ans << endl;
}