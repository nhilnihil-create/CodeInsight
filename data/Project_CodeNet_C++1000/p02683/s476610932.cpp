#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1e9;

int main() {
    // bit
    int N, M, X;
    cin >> N >> M >> X;
    vector<int> C(N);
    vector<vector<int>> book(N, vector<int> (M));
    rep(i, N) {
        cin >> C[i];
        rep(j, M) cin >> book[i][j];
    }
    int ans = INF;
    for (int bit = 0; bit < (1<<N); bit++) {
        int temp = 0;
        vector<int> prog(M);
        for (int j = 0; j < N; j++) {
            if ((bit >> j) & 1) {
                temp += C[j];
                rep(k, M) {
                    prog[k] += book[j][k];
                }
            }
        }
        bool flag = true;
        rep(i, M) {
            if (prog[i] < X) {
                flag = false;
            }
        }
        if (flag) ans = min(ans, temp);
    }
    if (ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';
    return 0;
}