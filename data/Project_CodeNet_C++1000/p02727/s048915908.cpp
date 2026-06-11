#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

int main() {
    int X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vector<ll> red(A), green(B), none(C);
    rep(i, A) cin >> red[i];
    rep(i, B) cin >> green[i];
    rep(i, C) cin >> none[i];
    sort(red.rbegin(), red.rend());
    sort(green.rbegin(), green.rend());

    vector<ll> candidate;
    rep(i, X) candidate.push_back(red[i]);
    rep(i, Y) candidate.push_back(green[i]);
    rep(i, C) candidate.push_back(none[i]);
    sort(candidate.rbegin(), candidate.rend());

    ll ans = 0;
    rep(i, X + Y) ans += candidate[i];
    cout << ans << endl;
}
