#include <bits/stdc++.h>
#define loop(n) for (int _i = 0; _i < (n); _i++)
#define rep(i, r, n) for (int i = (r); i < (n); ++i)
#define ALL(obj) begin(obj), end(obj)
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int INF = 2100100100;
const int MOD = 1e9 + 7;

// 多次元 vector 生成
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

struct Edge {
    long long to;
};
using Graph = vector<vector<Edge>>;

int encode(int i, int j) {
    if (i < j) swap(i, j);
    return i * (i - 1) / 2 + j + 1;
}

int seen[2000000];
int d[2000000];
int dfs(const Graph &G, int now) {
    if (seen[now] == 2) return d[now];
    seen[now] = 1;
    for (auto e : G[now]) {
        if (seen[e.to] == 1) {
            cout << -1 << endl;
            exit(0);
        }
        chmax(d[now], dfs(G, e.to) + 1);
    }
    seen[now] = 2;
    return d[now];
}

int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    long long N;
    cin >> N;
    Graph G(N * (N - 1) / 2 + 1);
    rep(i, 0, N) {
        int now = 0;
        loop(N - 1) {
            int j;
            cin >> j;
            j--;
            int next = encode(i, j);
            G[now].push_back({next});
            now = next;
        }
    }

    cout << dfs(G, 0) << endl;
    return 0;
}
