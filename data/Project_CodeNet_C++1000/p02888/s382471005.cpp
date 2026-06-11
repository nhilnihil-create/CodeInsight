
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

    vll L(N);
    REP(i, N) cin >> L[i];

    vector<int> C(1e4, 0);
    REP(i, N) C[L[i]]++;
    FOR(i, 1, C.size()) C[i] += C[i - 1];

    ll ans = 0;
    REP(i, N) FOR(j, i+1, N) {
        ll a = L[i], b = L[j];

        ll l = max(a - b, b - a);
        ll r = a + b - 1;

        if (C[r] - C[l] < 1) continue;

        ans += C[r] - C[l];

        if (l < a && a <= r) ans--;
        if (l < b && b <= r) ans--;
    }

    print(ans / 3);

    
}
