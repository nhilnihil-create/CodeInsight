#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<ll, ll> pll;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
/* global variables */
/* function */
/* main */
int main(){
    ll N, D, A;
    cin >> N >> D >> A;
    vector<pll> v(N + 1);
    ll x, h;
    for (int i = 0; i < N; i++) {
        cin >> x >> h; v[i] = pll(x, h);
    }
    v[N] = pll(LINF, 0);
    sort(v.begin(), v.end());

    vector<ll> sum(N + 1);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        x = v[i].first, h = v[i].second;
        h += sum[i];
        if (h <= 0) { sum[i+1] += sum[i]; continue; }
        int cnt = ceil((double) h / A);
        ans += cnt;
        sum[i] += -A * cnt;
        int upper = lower_bound(v.begin(), v.end(),
                    make_pair(x + 2*D + 1, numeric_limits<ll>::min())) - v.begin();
        sum[upper] += A * cnt;
        sum[i+1] += sum[i];
    }
    cout << ans << '\n';
}
