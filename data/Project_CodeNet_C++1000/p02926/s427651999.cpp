#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr ll mod = 1e9 + 7;

template <typename T> inline bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> inline bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

const double pi = acos(-1.0);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    ll X[100], Y[100];
    rep(i, n) cin >> X[i] >> Y[i];
    ll ans = 0;
    rep(i, 360) {
        ll x = 0, y = 0;
        rep(j, n) {
            if(cos(i * pi / 180) * X[j] + sin(i * pi / 180) * Y[j] > 0.0) {
                x += X[j];
                y += Y[j];
            }
        }
        chmax(ans, x * x + y * y);
    }
    printf("%.12f\n", sqrt(ans));
}