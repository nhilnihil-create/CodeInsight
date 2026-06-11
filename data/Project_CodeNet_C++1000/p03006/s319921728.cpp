#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define int long long
#define double long double
const int INF = 1e18, MOD = 1e9 + 7;

struct UnionFind {
    vector<int> t;
    UnionFind(int size): t(size, -1) {}
    int root(int x) {return t[x] < 0 ? x : t[x] = root(t[x]);}
    int size(int x) {return -t[root(x)];}
    bool isSame(int x, int y) {return root(x) == root(y);}
    bool unite(int x, int y) {
        x = root(x), y = root(y);
        if(x != y) {
            if(t[y] < t[x]) swap(x, y);
            t[x] += t[y], t[y] = x;
        }
        return x != y;
    }
};

signed main() {
    int n;
    cin>>n;
    int x, y;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        cin>>x>>y;
        v.push_back(make_pair(x, y));
    }
    int ans = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int p, q;
            p = v[i].first - v[j].first;
            q = v[i].second - v[j].second;
            UnionFind uf(n);
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    if (
                        v[k].first + p == v[l].first &&
                        v[k].second + q == v[l].second
                    ) {
                        uf.unite(k, l);
                    }
                }
            }
            int cnt = 0;
            for (int k = 0; k < n; k++) {
                if (uf.root(k) == k) cnt++;
            }
            ans = min(ans, cnt);
        }
    }
    cout<<ans<<endl;
}