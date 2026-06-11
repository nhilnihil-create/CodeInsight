#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int MOD = 1000000009;
const long long INF = 1LL << 60;

int main() {
    int N, M, X;
    cin >> N >> M >> X;
    vector<int> C(N);
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
        }
    }
    ll res = INF;
    for (int bit = 0; bit < (1<<N); ++bit) {
        vector<int> status(M, 0);
        ll money = 0;
        for (int i = 0; i < N; ++i) {
            if (bit & (1<<i)) {
                for (int j = 0; j < M; ++j) {
                    status[j] += A[i][j];
                }
                money += C[i];
            }
        }
        int tmp = 0;
        for (auto&& s : status) {
            if (s >= X) ++tmp;
        }
        if (tmp == M) {
            res = min(res, money);
        }
    }
    if (res != INF) cout << res << endl;
    else cout << -1 << endl;
    return 0;
}