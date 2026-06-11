#include <bits/stdc++.h>
#define SORT(a) sort(a.begin(), a.end())
#define RSORT(a) sort(a.rbegin(), a.rend())
#define REP(i, n) for (int i = 0; i < n; i++)
#define RREP(i, n) for (int i = n - 1; 0 <= i; i--)
#define FOR(i, start, end) for (int i = start; i < end; i++)
#define RFOR(i, start, end) for (int i = start - 1; 0 <= i; i--)
#define ALL(a) a.begin(), a.end()
using ll = long long;
using namespace std;
constexpr int INF32       = 1'050'000'000;
constexpr long long INF64 = 4'000'000'000'000'000'000;
constexpr int MOD7        = 1'000'000'007;
constexpr int MOD9        = 1'000'000'009;
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
void debug() { std::cerr << '\n'; }
template <class H, class... T> void debug(H &&head, T &&... args) {
    std::cerr << head;
    sizeof...(args) == 0 ? std::cerr << "" : std::cerr << ' ';
    debug(std::forward<T>(args)...);
}
template <class T> void debug(std::vector<T> &v) {
    for (int i = 0; i < v.size(); i++) {
        std::cerr << v[i];
        i == v.size() - 1 ? std::cerr << '\n' : std::cerr << ' ';
    }
}
template <class T> void debug(std::vector<std::vector<T>> &v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            std::cerr << v[i][j];
            j == v[i].size() - 1 ? std::cerr << '\n' : std::cerr << ' ';
        }
    }
}

struct graph {
    vector<vector<int>> gph;
    vector<int> indeg, outdeg;
    int vertex;
    graph(int N) : vertex(N) {
        gph.resize(vertex);
        indeg.resize(N);
        outdeg.resize(N);
    }
    // 有向グラフの構築
    void directed_update(int in, int out) {
        gph.at(in).emplace_back(out);
        indeg.at(in)++;
        outdeg.at(out)++;
    }
    // 無向グラフの構築
    void undirected_update(int x, int y) {
        gph.at(x).emplace_back(y);
        gph.at(y).emplace_back(x);
    }
};

class DAG {
  private:
    bool done_tsort;
    vector<int> used;
    graph g;

  public:
    vector<int> tsorted, dp;
    vector<vector<int>> parents;
    DAG(const graph &_g)
        : done_tsort(false), g(_g), used(_g.outdeg), parents(_g.vertex),
          dp(_g.vertex) {
        tsorted.reserve(g.vertex);
    }
    void tsort() {
        if (done_tsort)
            return;
        queue<int> que;
        for (int i = 0; i < g.vertex; i++) {
            if (used.at(i) == 0)
                que.push(i);
        }
        while (!que.empty()) {
            int now = que.front();
            que.pop();
            tsorted.emplace_back(now);
            for (auto &&i : g.gph.at(now)) {
                used.at(i)--;
                parents.at(i).emplace_back(now);
                if (used.at(i) == 0) {
                    que.push(i);
                    dp.at(i) = max(dp.at(i), dp.at(now) + 1);
                }
            }
        }
        done_tsort = true;
        return;
    }
    bool is_DAG() {
        if (!done_tsort)
            tsort();
        return tsorted.size() == g.vertex;
    }
    int longest_path() {
        if (!done_tsort)
            tsort();
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int V, E;
    cin >> V >> E;
    auto g = graph(V);
    REP(i, E) {
        int a, b;
        cin >> a >> b;
        g.directed_update(a, b);
    }
    auto dag = DAG(g);
    dag.tsort();
    for (auto &&i : dag.tsorted) {
        print(i);
    }

    return 0;
}
