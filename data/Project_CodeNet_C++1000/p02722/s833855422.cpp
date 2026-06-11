
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
#define FOR(i, m, n) for (ll i = (m); i < (n); ++i)
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

void divisor(ll n, set<ll>& ret) {
    for(ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            ret.insert(i);
            if (i * i != n) ret.insert(n/i);
        }
    }
}

int solve(ll N) {
    if (N == 2) {
//        print(1);
        return 1;
    }

    ll ans = 0;

    set<ll> a;
    divisor(N - 1, a);
    a.insert(N - 1);
    ans += a.size();

    set<ll> b;
    divisor(N, b);
    b.insert(N);

    debug(a, b)

    for(auto e: b) {
        ll n = N;
        while(n % e == 0) n /= e;

        if (n % e == 1) ans++;
    }

    return ans;
}

void naive(int N, vll& ret) {
    FOR(i, 2, N + 1) {
        int n = N;

        while(n % i == 0) n /= i;

        if(n % i == 1) ret.pb(i);
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N;
    cin >> N;

    print(solve(N));

}
