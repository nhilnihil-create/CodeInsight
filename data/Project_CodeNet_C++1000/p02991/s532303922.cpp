#include <iostream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <unordered_set>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

constexpr ll inf = INT64_MAX / 4;
constexpr double pi = asin(1) * 2;
constexpr ll mod = 1000000007;


ll mpow(ll base, ll power) {
    if (power == 0) return 1;
    ll t = mpow(base, power / 2);
    return (t * t * (power % 2 ? base : 1)) % mod;
}

int main() {
    int n, m, s, t;
    map<int, set<int>> p;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        p[u].insert(v);
    }
    cin >> s >> t;
    queue<pair<pair<int, int>, int>> q;
    map<pair<int, int>, int> r;
    q.push(make_pair(make_pair(0, 0), s));
    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        for (auto &e:p[v.second]) {
            int b = (v.first.second + 1) % 3;
            int c = v.first.first + (v.first.second == 2 ? 1 : 0);
            auto k = make_pair(e, b);
            if (r.find(k) == r.end()) {
                r[k] = c;
                q.push(make_pair(make_pair(c, b), e));
            }
        }
    }
    cout << (r.find(make_pair(t, 0)) == r.end() ? -1 : r[make_pair(t, 0)]) << endl;
}
