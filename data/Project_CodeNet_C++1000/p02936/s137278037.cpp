#include <bits/stdc++.h>
using namespace::std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef array<int, 3> tri;
typedef long double ld;

template <class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}
template <class T> ostream& operator<<(ostream &O, const vector<T>& v) {for (const T &e: v) O << e << ' '; return O;}

const int N = 2e5 + 7;
vector<int> adj[N];
vector<int> sts;
vector<int> where;
int here;


void dfs(int a, int p) {
        where[a] = ++here;
        sts[a] = 1;
        for (auto b: adj[a]) {
                if (p ^ b) {
                        dfs(b, a);
                        sts[a] += sts[b];
                }
        }
}


void _main() {
        int n, q; cin >> n >> q;
        sts.resize(n+2), where.resize(n+2);
        for (int i = 1; i <= n-1; i++) {
                int a, b; cin >> a >> b;
                adj[a].emplace_back(b);
                adj[b].emplace_back(a);
        }

        dfs(1, 0);
        vector<ll> ans(n + 1);
        while (q--) {
                int a, b; cin >> a >> b;
                ans[where[a]] += b;
                ans[where[a] + sts[a]] -= b;
        }

        for (int i = 1; i <= n + 1; i++) ans[i] += ans[i - 1];
        for (int i = 1; i <= n; i++) cout << ans[where[i]] << ' ';
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//        freopen("input.txt", "r", stdin);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}