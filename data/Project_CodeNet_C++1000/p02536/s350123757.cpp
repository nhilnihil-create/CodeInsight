#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int64_t i6;
typedef std::vector<std::vector<int64_t> > Graph;

#define rep(i, n) for (int64_t i = 0; i < n; ++i)
#define rep2(i, n) for (int64_t i = 1; i <= n; ++i)
#define repb(i, l, n) for (int64_t i = l; i < n; ++i)
#define repb2(i, l, n) for (int64_t i = l; i <= n; ++i)
#define repe(a, b) for (auto&(a) : (b))
#define ALL(v) (v).begin(), (v).end()
#define Sort(x) sort(ALL(x))
#define Sort_rev(x) Sort(x);reverse(ALL(x))
#define mp(a, b) make_pair((a), (b))
#define Push_back(a, b) push_back( mp( (a), (b) ) )

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;  } return 0;  }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;  } return 0;  }
template<typename V,typename T> bool find_num(V v, T num) { if ( find(ALL(v), num) == v.end() ) { return false; } return true; }

const int inf = 0x3fffffff;
const int64_t INF = 0x3fffffffffffffff;
const int64_t MOD = 1e9+7;

void bfs ( Graph G ) {
    std::vector<int64_t> seen(G.size(), 0);
    int64_t ans = 0;
    rep(i, G.size()) {
        if ( G[i].size() == 0 ) {
            ans++;
            continue;
        }
        if ( seen[i] == 1 ) continue;
        ans++;
        queue<int64_t> q;
        // int64_t start_num = 0;
        q.push(i);
        while ( !q.empty() ) {
            int64_t num = q.front();
            seen[num] = 1;
            q.pop();
            rep(i, G[num].size()) {
                int64_t see = G[num].at(i);
                if ( seen[see] == 0 ) {
                    q.push(see);
                    seen[see] = 1;
                }
            }
        }
    }

    cout << ans-1 << endl;
    return;
}

int main() {
    int64_t n, m;
    cin >> n >> m;
    std::vector<int64_t> a(m), b(m);
    Graph G(n);
    rep(i, m) {
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    bfs(G);
    return 0;
}
