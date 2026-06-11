#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

#define REP(k, n) for (ll k = 0; k < (ll)(n); ++k)
#define REPREV(k, n) for (ll k = (ll)(n)-1; k >= 0; --k)
#define FOR(k, a, b) for (ll k = (ll)(a); k < (ll)(b); ++k)
#define FORREV(k, a, b) for (ll k = (ll)(b)-1; k >= (ll)(a); --k)
#define FOREACH(e, v) for (auto e : v)

#define TGET(t, i) get<i>(t)
#define TSET(t, i, a) get<i>(t) = a
// MinHeap - priority_queue<ll, vll, greater<ll>> pq;

#define EVEN(n) ((n)&1) == 0
#define ODD(n) ((n)&1) == 1
#define MOD(x, m) ((x) % (m) + (m)) % (m)

#define SORT(v) sort(v.begin(), v.end())
#define SORTREV(v) sort(v.rbegin(), v.rend())
#define SHUFFLE(v) random_shuffle(v.begin(), v.end())
//srand(unsigned(time(0)));

#define REMOVEAT(v, i) v.erase(v.begin() + i)
#define REVERSE(v) reverse(v.begin(), v.end())

template <typename T>
void join(vector<T>& arr, string sep) {
    bool first = true;
    for (auto t : arr) {
        if (first) {
            first = false;
            cout << t;
        } else {
            cout << sep << t;
        }
    }
    cout << "\n";
}

#define POS "POSSIBLE"
#define IMPOS "IMPOSSIBLE"

// #define INF LLONG_MAX
// #define MINF LLONG_MIN
#define INF 9e18
#define MINF -INF

const ll m = 1e9+7;

ll power(ll a, ll b, ll m) {
    ll res = 1;
    while (b > 0) {
        if (b % 2 == 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    ll res = 0;
    vll dp(k+1);
    FORREV(i, 1, k+1) {
        dp[i] = k / i;
        dp[i] = power(dp[i], n, m);
        FOR(j, 2, k+1) {
            if (j * i > k)
                break;
            dp[i] = MOD(dp[i] - dp[j*i], m);
        }
        res = MOD(res + MOD(dp[i] * i, m), m);
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();

    return 0;
}