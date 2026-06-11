#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ar array
#define ull unsigned long long
#define ld long double
#define uint unsigned int
struct debug {
~debug() {cerr << "\n";}template<class C> debug& operator<<(C c) {cerr << c;return *this;}
};
#define var(x) " [" << #x << ": " << x << "]"

int n, k;

struct uf {
    vector<int> p;
    uf(int x) {
        p.assign(x, -1);
    }
    int root(int v) {
        return p[v]<0?v:(p[v]=root(p[v]));
    }
    bool same(int x, int y) {
        return root(x)==root(y);
    }
    void unite(int x, int y) {
        x=root(x), y=root(y);
        if(x!=y) {
            if(p[x]>p[y]) swap(x, y);
            p[x]+=p[y];
            p[y]=x;
        }
    }
};

void solve() {
    cin >> n >> k;
    uf a(n);
    for(int i=0; i<k; ++i) {
        int u, v;
        cin >> u >> v;
        u-=1, v-=1;
        a.unite(u, v);
    }
    int ans=0;
    for(int i=0; i<n; ++i) {
        if(a.root(i)==i) ans+=1;
    }
    cout << ans-1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}