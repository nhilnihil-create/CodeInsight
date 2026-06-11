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

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void solve() {
    ll N;
    cin >> N;
    ll ans = 0;
    for (ll x = 1; x < 10; x++) {
        for (ll y = 1; y < 10; y++) {
            ll cnt1 = 0, cnt2 = 0;
            for (ll i = 1; i <= N; i++) {
                ll t = i % 10;
                ll h;
                ll i_cpy = i;
                while (i_cpy >= 10) {
                    i_cpy /= 10;
                }
                h = i_cpy;

                if (h == x && t == y) {
                    ++cnt1;
                }
                if (t == x && h == y) {
                    ++cnt2;
                }
            }
            ans += cnt1 * cnt2;
        }
    }

    cout << ans << "\n";
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif
#ifdef FILEOUTPUT
    ofstream ofs("./in_out/output.txt");
    cout.rdbuf(ofs.rdbuf());
#endif
    solve();
    cout << flush;
    return 0;
}