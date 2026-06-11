#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define vv(T) vector<vector<T>>
using namespace std;
using ll = long long;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using vbool = vector<bool>;
using vvbool = vector<vector<bool>>;
using qint = queue<int>;
using sint = stack<int>;
using pii = pair<int, int>;

class UnionFind{
    vector<int> parent;
    // UnionFind木の実装
public:
    UnionFind(int N) : parent(N, -1) {} // コンストラクタ
    int root(int x){
        // 根を求める。
        if(parent[x] < 0) return x;
        return parent[x] = root(parent[x]);
    }
    void unite(int x, int y){
        // xとyの木を結合する。
        int rx = root(x);
        int ry = root(y);
        if(rx == ry) return;
        if(-parent[rx] > -parent[ry]){
            // 小さい方の木を大きい方につなげる。
            parent[rx] += parent[ry];
            parent[ry] = rx;
        }
        else{
            parent[ry] += parent[rx];
            parent[rx] = ry;
        }
        return;
    }
    bool isSame(int x, int y){
        // 同じ木にあるか?
        return root(x) == root(y);
    }
    int size(int x){
        // xの木に属する要素はいくつか?
        return -parent[root(x)];
    }
};

int main(){
    int n, m;
    cin >> n >> m;

    UnionFind uf(n);

    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        uf.unite(a, b);
    }

    int ans = 0;
    rep(i, n){
        ans = max(ans, uf.size(i));
    }

    cout << ans << endl;
    return 0;
}