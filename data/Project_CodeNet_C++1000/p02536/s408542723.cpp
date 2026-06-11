#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;
const int mod = 1000000007;
struct UnionFind{
    vector<int> d;
    UnionFind(int n=0):d(n,-1){}
    int root(int x){
        if(d[x] < 0) return x;
        return d[x] = root(d[x]);
    }
    void unite(int x,int y){
        int root_x = root(x);
        int root_y = root(y);
        if(root_x == root_y) return;
        if(d[root_x] > d[root_y]) swap(root_x,root_y);
        d[root_x] += d[root_y];
        d[root_y] = root_x;
    }
    bool same(int x,int y){return root(x) == root(y);}
    int size(int x){return -d[root(x)];}
};

int main(){
    int n,m;
    cin >> n >> m;
    UnionFind uf(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        uf.unite(a,b);
    }
    int ans = 0;
    rep(i,n) if(uf.d.at(i) < 0) ans++;
    ans = max(ans-1,0);
    cout << ans << endl;
}