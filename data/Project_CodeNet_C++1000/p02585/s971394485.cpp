
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <prettyprint.hpp>
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}

template <typename T>
void print(T x) {
    cout << x << "\n";
}

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REVFOR(i, m, n) for (int i = (n - 1); i >= (m); --i)
#define REP(i, n) FOR(i, 0, n)
#define REVREP(i, n) REVFOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;
ll MOD = 1e9+7;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    ll n, k;
    cin >> n >> k;

    vector<ll> P(n), C(n);
    REP(i, n) cin >> P[i];
    REP(i, n) P[i]--;
    REP(i, n) cin >> C[i];

    ll ans = C[0];
    REP(i, n) {
        vector<ll> c;
        vector<bool> used(n, false);

        int cur = i;
        while(!used[cur]) {
            used[cur] = true;
            cur = P[cur];
            c.pb(C[cur]);
        }

        ll sum = -INF;

        ll tmp = 0;
        REP(i, c.size()) {
            tmp += c[i];
            if (i + 1 <= k) sum = max(sum, tmp);
        }

        if (tmp > 0) {
            if (k > c.size()) {
                tmp = tmp * (k / (int)c.size() - 1);
                sum = max(tmp, sum);
                REP(j, c.size()) {
                    tmp += c[j];
                    sum = max(tmp, sum);
                }

                REP(j, k % c.size()) {
                    tmp += c[j];
                    sum = max(tmp, sum);
                }
            }
        }

        ans = max(ans, sum);
    }

    print(ans);
    
}
