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
    ll N, K;
    cin >> N >> K;

    if (K > (N - 1) * (N - 2) / 2) {
        cout << -1 << endl;
        return;
    }

    vector<Pii> edges;
    for (ll i = 2; i <= N; i++) {
        edges.emplace_back(1, i);
    }

    ll cnt = (N - 1) * (N - 2) / 2;
    ll ucur = 2, vcur = 3;
    while (cnt > K) {
        edges.emplace_back(ucur, vcur);
        --cnt;
        if (vcur < N) {
            ++vcur;
        }
        else {
            ++ucur;
            vcur = ucur + 1;
        }
    }

    cout << edges.size() << "\n";
    for (const auto& p : edges) {
        cout << p.first << " " << p.second << "\n";
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