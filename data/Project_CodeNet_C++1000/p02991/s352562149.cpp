#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

#define int long long
#define ll long long
#define double long double
#define pii pair<int, int>
#define vec vector
#define u_map unordered_map
#define u_set unordered_set
#define str string
#define all(el) el.begin(), el.end()
#define allr(el) el.rbegin(), el.rend()
#define sz(el) (int)el.size()
#define f first
#define s second
#define pb push_back
#define in insert
#define mp make_pair
#define endl "\n"
#define forn(i, n) for (int i = 0; i < n; ++i)

inline int maxi(int &a, int b) { if (b > a) { a = b; return 1; } return 0; }

inline int mini(int &a, int b) { if (b < a) { a = b; return 1; } return 0; }

inline int maxi(double &a, double b) { if (b > a) { a = b; return 1; } return 0; }

inline int mini(double &a, double b) { if (b < a) { a = b; return 1; } return 0; }

const int maxN = 1e5 + 100;

int used[3 * maxN];
int d[3 * maxN];
vec<int> g[3 * maxN];

signed main() {

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        u *= 3;
        v *= 3;
        g[u].pb(v + 1);
        g[u + 1].pb(v + 2);
        g[u + 2].pb(v);
    }
    int s, t;
    cin >> s >> t;
    s--, t--;
    s *= 3;
    t *= 3;
    queue<int> q;
    q.push(s);
    used[s] = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int to : g[v]) {
            if (!used[to]) {
                used[to] = 1;
                q.push(to);
                d[to] = d[v] + 1;
            }
        }
    }
    if (d[t] != 0) {
        cout << d[t] / 3;
    } else {
        cout << -1;
    }
    return 0;
}