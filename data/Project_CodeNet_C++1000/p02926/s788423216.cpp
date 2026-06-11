#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pa;
const ll MOD = 1e9 + 7;

#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for (int i = (n)-1; i >= 0; i--)
#define repe(i, l, r) for (int i = (l); i < (r); i++)
#define reper(i, l, r) for (int i = (r)-1; i >= (l); i--)

void init() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
}
//-----------------------------------------------------------//
long double sq(ll x, ll y) {
    return x * x + y * y;
}

int main() {
    init();
    int N;
    cin >> N;
    vector<ll> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];
    vector<ll> ivec(N);
    iota(all(ivec), 0);
    sort(all(ivec), [&](ll i, ll j) {
        return atan2(y[i], x[i]) < atan2(y[j], x[j]);
    });

    rep(i, N) ivec.eb(ivec[i]);

    long double ans = 0, tmp = 0, tans = 0;
    ll tx, ty;
    rep(i, N) {
        tx = 0;
        ty = 0;
        tans = 0;
        rep(j, N) {
            tx += x[ivec[i + j]];
            ty += y[ivec[i + j]];
            tmp = sq(tx, ty);
            if (tmp > tans) {
                tans = tmp;
                ans = max(ans, tans);
            } else {
                tx -= x[ivec[i + j]];
                ty -= y[ivec[i + j]];
            }
        }
    }
    cout << sqrt(ans) << endl;
    return 0;
}