#include <bits/stdc++.h>
#define LOOP(n) for (int _i = 0; _i < (n); _i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, r, n) for (int i = (r); i < (n); ++i)
#define ALL(obj) begin(obj), end(obj)
using namespace std;
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
const int INF = 2100100100;
const int MOD = 1e9 + 7;

int N, M, K, Q, W, H, R, C;
string S;

int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);

    cin >> N >> K;
    vector<vector<int>> G = make_vec<int>(N, N);
    REP(i, N) {
        REP(j, N) { G[i][j] = 1; }
    }

    if (N == 2) {
        if (K == 0) {
            cout << 1 << endl;
            cout << "1 2" << endl;

        } else {
            cout << -1 << endl;
        }
        return 0;
    }

    if (K > (N - 1) * (N - 2) / 2) {
        cout << -1 << endl;
        return 0;
    } else {
        int cnt = 0;
        REP(i, N) {
            if (cnt == K) break;
            FOR(j, i + 1, N - 1) {
                if (cnt == K) break;
                G[i][j] = 0;
                cnt++;
            }
        }

        cout << N * (N - 1) / 2 - K << endl;
        REP(i, N) {
            FOR(j, i + 1, N) {
                if (G[i][j] > 0) {
                    cout << i + 1 << " " << j + 1 << endl;
                }
            }
        }
        return 0;
    }
}
