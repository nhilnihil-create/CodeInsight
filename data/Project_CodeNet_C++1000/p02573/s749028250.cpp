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

ll modComb(ll n, ll k) {
    ll tmp = 1;
    for (int i = 0; i < k; i++) {
        tmp *= n - i;
        tmp %= MOD;
    }
    for (int i = 1; i <= k; i++) {
        tmp *= modInv(i);
        tmp %= MOD;
    }
    return tmp;
}

vector<ll> graph[200010];

//start_sumは最初の人間の番号
//返り値はグラフの要素の総和
ll bfs(ll start_num, vector<bool>& checked) {
    ll graph_sum = 1;

    queue<ll> next_num;
    next_num.push(start_num);
    checked[start_num] = true;

    while (!next_num.empty()) {
        for (ll i = 0; i < (ll)graph[next_num.front()].size(); i++) {
            ll tmp_next_num = graph[next_num.front()][i];
            if (!checked[tmp_next_num]) {
                checked[tmp_next_num] = true;
                next_num.push(tmp_next_num);
                graph_sum++;
            }
        }
        next_num.pop();
    }
    return graph_sum;
}

int main() {

    ll N, M;
    
    vector<bool> checked(200010, false);
    
    ll ans = 0;

    cin >> N >> M;
    rep(i, M) {
        ll A, B;
        cin >> A >> B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }

    for (ll i = 1; i <= N; i++) {
        if (!checked[i]) {
            ll graph_sum = bfs(i, checked);
            ans = max(ans, graph_sum);
        }
    }

    cout << ans << endl;
}