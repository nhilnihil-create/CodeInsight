#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#pragma region Macros
#define FOR(i, m, n) for (ll i = (ll)(m); i < (ll)(n); i++)
#define rep(i, n) FOR(i, 0, n)

template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template <class T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }

template <class T> string join(const T &v, const string delim = ",")
{
    if (v.empty())
        return "";

    ostringstream res;
    res << v[0];
    for (int i = 1; i < v.size(); i++)
    {
        res << delim << v[i];
    }
    return res.str();
}

#ifdef LOCAL
#define dbg(x) cerr << __LINE__ << ":" << #x << " = " << (x) << endl;
#else
#define dbg
#endif

#pragma endregion Macros
struct UnionFind {
    vector<int> par;
    UnionFind(int n) : par(n, -1) {
    }

    int root(int x) {
        if (par[x] < 0) {
            return x;
        }
        int r = root(par[x]);
        par[x] = r;
        return r;
    }

    bool same(int a, int b) {
        return root(a) == root(b);
    }

    void unite(int a, int b) {
        int ra = root(a);
        int rb = root(b);
        if (ra == rb)
            return;

        if (par[ra] < par[rb]) {
            swap(ra, rb);
        }
        par[ra] += par[rb];
        par[rb] = ra;
    }

    int size(int x) {
        return -par[root(x)];
    }
};
int main()
{
    int N, M;
    cin >> N >> M;

    UnionFind uf(N);

    rep(i,M){
        int A,B;
        cin >> A >> B;
        A--;
        B--;
        uf.unite(A, B);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        chmax(ans, uf.size(i));
    }

    cout << ans << endl;
}
