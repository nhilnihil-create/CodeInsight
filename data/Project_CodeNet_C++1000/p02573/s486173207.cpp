#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
#define RALL(c) (c).rbegin(),(c).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const ll INF = 1e18 + 10;

int N, M;

struct UnionFind {
    //自身が親であれば、その集合に属する頂点数に-1を掛けたもの
    //そうでなければ親のid
    vector<int> r;
 
    UnionFind(int N) {
        r = vector<int>(N, -1);
    }
 
    int root(int x) {
        if (r[x] < 0) return x;
        return r[x] = root(r[x]);
    }
 
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (r[x] > r[y]) swap(x, y);
        r[x] += r[y];
        r[y] = x;
        return true;
    }
 
    int size(int x) {
        return -r[root(x)];
    }
};

int main() {
    cin >> N >> M;
    UnionFind uf(N);
    rep(i,M) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        uf.unite(a,b);
    }
    int res = 0;
    rep(i,N) {
        chmax(res, uf.size(i));
    }
    cout << res << endl;
}