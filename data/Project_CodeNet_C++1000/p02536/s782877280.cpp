#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
typedef pair<int, int> P;

struct UnionFind
{
    vector<int> par, rank;

    UnionFind(int N) : par(N), rank(N)
    {
        rep(i, N) par[i] = i, rank[i] = 0;
    }

    int root(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry)
            return;
        if (rank[rx] < rank[ry])
        {
            par[rx] = ry;
        }
        else
        {
            par[ry] = rx;
            if (rank[rx] == rank[ry])
                rank[rx]++;
        }
    }

    bool same(int x, int y)
    {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    UnionFind tree(N);

    rep(i, M) {
        int A, B;
        cin >> A >> B;
        A--; B--;
        tree.unite(A, B);
    }

    set<int> st;
    rep(i, N) {
        st.insert(tree.root(i));
    }

    int len = (int)st.size();
    cout << len - 1 << endl;
    return 0;
}