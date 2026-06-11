
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
    
    ll N, K;
    cin >> N >> K;

    vll A(N);
    REP(i, N) cin >> A[i];

    ll s = accumulate(ALL(A), 0LL);

    vector<ll> div;
    for(int i = 1; i * i <= s; ++i) {
        if (s % i == 0) {
            div.pb(i);

            if (i * i != s) div.pb(s / i);
        }
    }

    debug(div);

    ll ans = 1;
    for (auto &e: div) {
        vector<ll> R(N);
        REP(i, N) R[i] = A[i] % e;

        ll rs = accumulate(ALL(R), 0LL);
        if (rs % e != 0) continue;

        sort(ALL(R));
        reverse(ALL(R));

        debug(R)

        ll cnt = 0, p = rs / e;
        int i = 0;
        while(p > 0) {
            --p;
            cnt += e - R[i++];
        }

        if (cnt <= K) ans = max(e, ans);
    }

    print(ans);
    
}
