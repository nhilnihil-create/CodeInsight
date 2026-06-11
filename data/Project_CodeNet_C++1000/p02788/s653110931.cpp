#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    int N, D, A; cin >> N >> D >> A;
    vector<pair<ll, ll>> XH(N);
    REP(i, 0, N) cin >> XH[i].first >> XH[i].second;
    sort(ALL(XH));

    ll ans = 0;
    vector<ll> damage(N + 2);
    REP(i, 0, N) {
        damage[i + 1] += damage[i];
        // cout << "# i : " << i << ", damage : " << damage[i + 1] << endl;
        if (XH[i].second - damage[i + 1] < 1) continue;
        ll cnt = (XH[i].second - damage[i + 1] + A - 1) / A;
        
        int idx = lower_bound(ALL(XH), make_pair(XH[i].first + (ll)2 * D + 1, 0LL)) - XH.begin();
        damage[i + 1] += cnt * A;
        damage[idx + 1] -= cnt * A;
        // cout << "# i : " << i << ", cnt : " << cnt << ", idx : " << idx << endl;
        ans += cnt;
    }
    cout << ans << endl;
    return 0;
}