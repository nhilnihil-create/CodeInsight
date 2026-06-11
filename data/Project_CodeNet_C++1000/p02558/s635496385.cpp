#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

template<typename T1,typename T2>ostream& operator<<(ostream& os,const pair<T1,T2>& a) {os << "(" << a.first << ", " << a.second << ")";return os;}

const char newl = '\n';

struct UnionFind {
private:
    vector<int> par,depth;
public:
    UnionFind (int n) {
        par.resize(n);
        depth = vector<int>(n,0);
        for (int i = 0;i < n;++i) par[i] = i;
    }

    int find(int x) {
        if (par[x] == x) return x;
        else return par[x] = find(par[x]);
    }

    void unite(int x,int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (depth[x] < depth[y]) par[x] = y;
        else {
            par[y] = x;
            if (depth[x] == depth[y]) depth[x]++;
        }
    }

    bool same(int x,int y) {
        return find(x) == find(y);
    }
};

int main() {
    int n,q;
    cin >> n >> q;
    UnionFind uf(n);
    while (q--) {
        int t,u,v;
        cin >> t >> u >> v;
        if (t == 0) uf.unite(u,v);
        else cout << uf.same(u,v) << newl;
    }
}