#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
template <class T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    int M = 0;
    Graph<int> G(N);
    for (int i = 1; i < N; ++i) {
        G[0].push_back(i);
        M++;
    }

    K = (N - 1) * (N - 2) / 2 - K;
    for (int i = 2; i < N && K > 0; ++i) {
        for (int j = 1; j < i && K > 0; ++j) {
            G[j].push_back(i);
            M++;
            K--;
        }
    }

    cout << (K >= 0 ? M : -1) << '\n';
    if (K >= 0) {
        for (int i = 0; i < N; ++i)
            for (auto j : G[i])
                cout << i + 1 << ' ' << j + 1 << '\n';
    }
    return 0;
}
