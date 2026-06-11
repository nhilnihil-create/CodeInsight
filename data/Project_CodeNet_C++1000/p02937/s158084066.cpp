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
    string S, T;
    cin >> S >> T;

    ll n = (ll)S.size();
    vector<Vi> pos(26);
    for (ll i = 0; i < n; i++) {
        pos[S[i] - 'a'].emplace_back(i);
    }

    bool ok = true;
    ll cur = -1;
    for (const auto& c : T) {
        ll a = c - 'a';
        ll b = cur / n;
        ll p = cur % n;

        if (pos[a].size() == 0) {
            ok = false;
            break;
        }

        ll idx = upper_bound(pos[a].begin(), pos[a].end(), p) - pos[a].begin();

        if (idx < (ll)pos[a].size()) {
            p = pos[a][idx];
        }
        else {
            ++b;
            p = pos[a][0];
        }

        cur = b * n + p;
    }

    if (ok)
        cout << cur + 1 << "\n";
    else
        cout << -1 << "\n";
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