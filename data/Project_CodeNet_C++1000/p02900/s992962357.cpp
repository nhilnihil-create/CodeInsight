
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

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

// return primes between [2, sqrt(N)]
void SOE(ll N, vi & p) {
    int m = int(floor(sqrt(N))) + 1;
    int s[m];
    REP(i ,m) s[i] = i;

    FOR (i, 2, m) {
        if (s[i] != i) continue;

        p.pb(i);

        for (int j = i+i; j <= m; j += i) {
            s[j] = i;
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    ll a, b;
    cin >> a >> b;

    ll l = gcd(a, b);

    vi prime;
    SOE(l, prime);

    map<int, int> m;
    for(auto e: prime) {
        while(l % e == 0) {
            l /= e;
            m[e]++;
        }
    }

    if (l > 1) m[l]++;

    print(m.size() + 1);
    
}
