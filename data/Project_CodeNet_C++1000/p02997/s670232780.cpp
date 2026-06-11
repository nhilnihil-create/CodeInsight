#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < (int)(n); i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
using ll = long long;

int main() {
    int N, K; cin >> N >> K;
    if ((N - 1) * (N - 2) / 2 < K) {
        cout << -1 << endl;
        return 0;
    }

    int total = (N - 1) * (N - 2) / 2;
    vector<pair<int, int>> ans;
    REP(i, 2, N + 1) ans.push_back({1, i});

    REP(i, 2, N + 1) {
        REP(j, i + 1, N + 1) {
            if (total == K) break;
            ans.push_back({i, j});
            total--;
        }
    }

    cout << ans.size() << endl;
    for (auto a : ans) cout << a.first << " " << a.second << endl;

    return 0;
}