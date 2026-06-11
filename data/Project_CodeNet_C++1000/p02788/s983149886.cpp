#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif

    ll N, D, A;
    cin >> N >> D >> A;
    vector<Pll> mos(N);
    for (int i = 0; i < N; i++) {
        cin >> mos[i].first >> mos[i].second;
    }

    sort(mos.begin(), mos.end());

    ll ans = 0;
    ll dmg = 0;
    queue<Pll> q;
    for (int i = 0; i < N; i++) {
        while (!q.empty()) {
            ll pos, d;
            tie(pos, d) = q.front();
            if (pos + D * 2 < mos[i].first) {
                dmg -= d;
                q.pop();
            }
            else {
                break;
            }
        }
        ll h = max(mos[i].second - dmg, 0LL);
        ll c = (h + A - 1) / A;
        ans += c;
        dmg += c * A;
        q.emplace(mos[i].first, c * A);
    }

    cout << ans << endl;

    return 0;
}