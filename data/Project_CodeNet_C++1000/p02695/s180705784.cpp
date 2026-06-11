#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pll = pair<ll, ll>;

#define rep(i, n) for (ll i = 0, xxx_rep_end = (n); i < xxx_rep_end; ++i)
#define all(x) (x).begin(), (x).end()

template <class T1, class T2>
inline bool chmax(T1 &a, const T2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T1, class T2>
inline bool chmin(T1 &a, const T2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

constexpr ll INF = 0x3f3f3f3f3f3f3f3fLL;
constexpr ll mod = 1000000007;

struct edge {
    int from, to, diff, score;
    edge(int f, int t, int d, int s) : from(f), to(t), diff(d), score(s) {}
};

int N, M, Q;
vector<edge> es;

int dfs(vector<int> &A) {
    int ret = 0;

    if (A.size() == N) {
        for (auto e : es) {
            if (A[e.to] - A[e.from] == e.diff) {
                ret += e.score;
            }
        }
        return ret;
    }

    int prev = A.empty() ? 1 : A.back();
    for (int i = prev; i <= M; ++i) {
        A.emplace_back(i);
        chmax(ret, dfs(A));
        A.pop_back();
    }

    return ret;
}
int main() {
    cin >> N >> M >> Q;
    rep(i, Q) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        --a;
        --b;
        es.emplace_back(a, b, c, d);
    }
    vector<int> A;
    cout << dfs(A) << endl;
}