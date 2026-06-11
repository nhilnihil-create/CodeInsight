
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
#define REP(i, n) FOR(i, 0, n)
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
    
    int N, K;
    cin >> N >> K;

    vi A(N);
    REP(i, N) cin >> A[i];

    REP(i, K) {

        vi r(N + 1, 0);

        REP(j, N) {
            int a = A[j];

            int s = max(j - a, 0);
            int t = min(j + a + 1, N);
            r[s] += 1;
            r[t] -= 1;

        }

        bool f = true;
        int s = 0;
        REP(j, N) {
            s += r[j];
            f &= (s == N);
            A[j] = s;
        }

        if (f) break;
    }

    REP(i, N) {
        if (i > 0) cout << " ";
        cout << A[i];
    }

    cout << endl;
    
}
