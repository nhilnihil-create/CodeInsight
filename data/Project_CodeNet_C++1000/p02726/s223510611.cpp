#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <list>
#include <numeric>
#include <stack>
#include <iomanip>
#include <random>
#include <complex>
#include <functional>
#include <tuple>
#include <new>

using namespace std;

#define EPS (1e-9)
#define INF (1e9)
#define MOD (ll)(1e9 + 7)
#define PI (acos(-1))
#define REP(i,a,n) for(int i=a;i<n;i++)
#define rep(i, n) REP(i,0,n)
#define allof(a) (a).begin(), (a).end()

#define Yes(q) ((q) ? "Yes" : "No")
#define YES(q) ((q) ? "YES" : "NO")
#define Possible(q) ((q) ? "Possible" : "Impossible")
#define POSSIBLE(q) ((q) ? "POSSIBLE" ; "IMPOSSIBLE")

using ll = long long int;

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll beki(ll a, ll b) {
    ll tmp = 1;
    rep(i, b) tmp *= a;
    return tmp;
}

ll modPow(ll x, ll a) {
    if (a == 1) return x;
    if (a % 2) return (x * modPow(x, a - 1)) % MOD;
    ll t = modPow(x, a / 2);
    return ((t % MOD) * (t % MOD)) % MOD;
}

ll modInv(ll x) {
    return modPow(x, MOD - 2);
}

int N, X, Y;
vector<int> v[2010];
vector<int> v_dis(2010, INF);
vector<int> ans(2010, 0);

void bfs(int f) {
    rep(i, 2010) v_dis[i] = INF;
    queue<int> q;
    q.push(f);
    int dis = 0;
    v_dis[f] = dis;
    while (!q.empty()) {
        rep(i, v[q.front()].size()) {
            if (v_dis[v[q.front()][i]] > v_dis[q.front()]) {
                v_dis[v[q.front()][i]] = v_dis[q.front()] + 1;
                q.push(v[q.front()][i]);
                //cout << q.front() + 1 << " " << v[q.front()][i] + 1 << endl;
                //cout << "dis" << v_dis[v[q.front()][i]] << endl;
            }
        }
        q.pop();
        //cout << endl;
    }
    rep(i, N) {
        if (i == f) continue;
        ans[v_dis[i]]++;
        //cout << "ans" << ans[v_dis[i]] << endl;
    }
    return;
}

int main() {
    cin >> N >> X >> Y;
    rep(i, N - 1) {
        v[i].push_back(i + 1);
        v[i + 1].push_back(i);
    }
    v[X - 1].push_back(Y - 1);
    v[Y - 1].push_back(X - 1);

    rep(i, N) bfs(i);
    REP(i, 1, N) cout << ans[i] / 2 << endl;
}

