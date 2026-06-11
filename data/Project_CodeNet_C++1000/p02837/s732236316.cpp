
#pragma GCC optimize ("O3")

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
    cout << x << endl;
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
    
    int N;
    cin >> N;

    vector<vector<int>> X(N), Y(N);
    REP(i, N) {
        int a; cin >> a;
        REP(j, a) {
            int x, y; cin >> x >> y;
            --x;
            X[i].pb(x);
            Y[i].pb(y);
        }
    }

    int ans = 0;
    REP(i, 1 << N) {
        bool f = true;
        REP(j, N) {
            if ((i >> j) % 2 == 0) continue;
            REP(k, X[j].size()) {
                int x = X[j][k], y = Y[j][k];
                if ((i >> x) % 2 == y) continue;
                f = false;
                break;
            }
            if (!f) break;
        }

        if (!f) continue;

        ans = max(bcnt(i), ans);
    }

    print(ans);
    
}
