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
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    string S;
    cin >> S;

    --A, --B, --C, --D;

    bool ok = true;

    for (ll i = A; i + 1 <= C; i++) {
        if (S[i] == '#' && S[i + 1] == '#') {
            ok = false;
        }
    }
    for (ll i = B; i + 1 < D; i++) {
        if (S[i] == '#' && S[i + 1] == '#') {
            ok = false;
        }
    }

    if (C > D) {
        bool ok2 = false;
        for (ll i = B; i <= D; i++) {
            if (S[i - 1] == '.' && S[i] == '.' && S[i + 1] == '.') {
                ok2 = true;
            }
        }
        ok &= ok2;
    }

    cout << (ok ? "Yes\n" : "No\n");
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