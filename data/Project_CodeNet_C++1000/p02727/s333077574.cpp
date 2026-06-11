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

ll X, Y, A, B, C;
vector<ll> p(100010), q(100010), r(100010);
priority_queue<ll, vector<ll>, greater<ll>> p_que, q_que;
ll ans = 0;

int main() {
    cin >> X >> Y >> A >> B >> C;
    rep(i, A) cin >> p[i];
    rep(i, B) cin >> q[i];
    rep(i, C) cin >> r[i];

    sort(p.begin(), p.end(), greater<ll>());
    sort(q.begin(), q.end(), greater<ll>());
    sort(r.begin(), r.end(), greater<ll>());

    rep(i, X) {
        p_que.push(p[i]);
        //cout << p[i] << endl;
    }
    rep(i, Y) {
        q_que.push(q[i]);
        //cout << q[i] << endl;
    }

    for (ll i = 0; min(p_que.top(), q_que.top()) < r[i]; i++) {
        if (p_que.top() <= q_que.top()) {
            p_que.pop();
            p_que.push(r[i]);
        }
        else {
            q_que.pop();
            q_que.push(r[i]);
        }
    }

    rep(i, X) {
        ans += p_que.top();
        p_que.pop();
    }

    rep(i, Y) {
        ans += q_que.top();
        q_que.pop();
    }

    cout << ans << endl;
}