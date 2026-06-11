#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, D, A;
    cin >> N >> D >> A;
    vector<ll> X(N), H(N + 100), diff(N + 100);
    map<ll, ll> ma;
    rep(i, N) {
        cin >> X[i] >> H[i];
        ma[X[i]] = H[i];
    }

    sort(all(X));
    rep(i, N) { H[i] = ma[X[i]]; }

    ll ans = 0;
    rep(i, N) {
        if (H[i] > 0) {
            ll tar = X[i] + 2 * D;
            int a = upper_bound(all(X), tar) - X.begin();
            ll cnt = (H[i] / A) + (H[i] % A != 0 ? 1 : 0);
            ans += cnt;
            H[a] += (A * cnt);
            diff[a] += (A * cnt);
            diff[i] -= (A * cnt);
        }
        H[i + 1] += diff[i];
        diff[i + 1] += diff[i];
    }

    cout << ans << endl;
}