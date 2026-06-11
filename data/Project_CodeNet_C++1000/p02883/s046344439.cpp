
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
    
    ll N, K;
    cin >> N >> K;

    vll A(N);
    REP(i, N) cin >> A[i];

    if (accumulate(ALL(A), 0LL) <= K) {
        print(0);
        return 0;
    }

    vll F(N);
    REP(i, N) cin >> F[i];

    sort(ALL(A));
    sort(ALL(F), greater<>());

    ll l = 0, r = INF;
    while(r - l > 1) {
        ll m = (l + r) / 2;

        ll k = 0;
        REP(i, N) {
            if (A[i] * F[i] > m) {
                ll tmp = A[i] - m / F[i] - 2;
                while (A[i] * F[i] - tmp * F[i] > m) tmp++;
                k += tmp;
            }
        }

        if (k > K) l = m;
        else r = m;
    }

    print(r);
}
