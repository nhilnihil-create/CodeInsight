#ifdef _DEBUG
#include ".vscode/debug_print.hpp"
#else
#define debug(...)
#endif
#include <bits/stdc++.h>

using ll = long long;
using ld = long double;
using namespace std;
constexpr int INF32       = 1050000000;
constexpr long long INF64 = 4000000000000000000;
constexpr int MOD7        = 1000000007;
constexpr int MOD53       = 998244353;
constexpr long double PI  = 3.14159265358979323846;
template <class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
void print() { std::cout << '\n'; }
template <class H, class... T> void print(H &&head, T &&... args) {
    std::cout << head;
    sizeof...(args) == 0 ? std::cout << "" : std::cout << ' ';
    print(std::forward<T>(args)...);
}
template <class T> void print(std::vector<T> &v) {
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i];
        i == v.size() - 1 ? std::cout << '\n' : std::cout << ' ';
    }
}
template <class T> void print(std::vector<std::vector<T>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            std::cout << v[i][j];
            j == v[i].size() - 1 ? std::cout << '\n' : std::cout << ' ';
        }
    }
}
void scan() {}
template <class H, class... T> void scan(H &&head, T &&... args) {
    std::cin >> head;
    scan(std::forward<T>(args)...);
}
template <class T> void scan(std::vector<T> &v) {
    for (auto &&i : v) {
        scan(i);
    }
}

void vprint() { std::cout << '\n'; }
template <class H, class... T> void vprint(H &&head, T &&... args) {
    std::cout << head;
    sizeof...(args) == 0 ? std::cout << "" : std::cout << '\n';
    vprint(std::forward<T>(args)...);
}
template <class T> void vprint(std::vector<T> &v) {
    for (auto &&i : v) {
        std::cout << i << '\n';
    }
}

class Dijkstra {
  private:
    struct Graph {
        int to, cost;
        Graph(int _to, int _cost) : to(_to), cost(_cost) {}
    };
    const long long INF = 4'000'000'000'000'000'000;
    using P             = std::pair<long long, int>;
    int V;
    std::vector<vector<Graph>> G;
    std::vector<long long> dist;

  public:
    Dijkstra(int vertex) {
        V = vertex;
        G.resize(vertex);
        dist.resize(vertex, INF);
    }
    // 無向グラフの構築
    void undirected_update(int x, int y, int cost) {
        G[x].emplace_back(y, cost);
        G[y].emplace_back(x, cost);
    }
    // 有向グラフの構築
    void directed_update(int from, int to, int cost) {
        G[from].emplace_back(to, cost);
    }

    // start からの最短経路計算
    void calc(int start) {
        std::priority_queue<P, std::vector<P>, std::greater<P>> que;
        dist[start] = 0;
        que.push({0, start});

        while (!que.empty()) {
            auto p = que.top();
            que.pop();
            int v = p.second;
            if (dist[v] < p.first)
                continue;
            for (size_t i = 0; i < G[v].size(); i++) {
                auto e = G[v][i];
                if (dist[v] + e.cost < dist[e.to]) {
                    dist[e.to] = dist[v] + e.cost;
                    que.push({dist[e.to], e.to});
                }
            }
        }
    }

    // 最短経路のメモリをリセットする
    void clear() { std::fill(dist.begin(), dist.end(), INF); }

    // calc で渡した start からの最短経路を返す
    // 最短経路が存在しないとき -1 を返す
    long long min_dist(int to) { return dist[to] != INF ? dist[to] : -1; }
};

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    int N, X, Y;
    scan(N, X, Y);
    auto g = Dijkstra(N);
    for (size_t i = 0; i < N - 1; i++) {
        g.undirected_update(i, i + 1, 1);
    }
    g.undirected_update(X - 1, Y - 1, 1);
    vector<int> ans(N - 1);
    for (size_t i = 0; i < N - 1; i++) {
        g.clear();
        g.calc(i);
        for (size_t j = i + 1; j < N; j++) {
            int dist = g.min_dist(j);
            ans[dist - 1]++;
        }
    }
    vprint(ans);

    return 0;
}