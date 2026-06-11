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

ll K;

void solve() {
    cin >> K;
    if (K < 10) {
        cout << K << "\n";
        return;
    }

    queue<ll> q;
    for (ll i = 1; i <= 9; i++) {
        q.emplace(i);
        --K;
    }

    while (true) {
        ll a = q.front();
        q.pop();
        ll d = a % 10;
        for (ll i = -1; i <= 1; i++) {
            if (d + i < 0 || d + i > 9) continue;
            ll an = a * 10 + d + i;
            --K;
            if (K == 0) {
                cout << an << "\n";
                return;
            }
            q.emplace(an);
        }
    }
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