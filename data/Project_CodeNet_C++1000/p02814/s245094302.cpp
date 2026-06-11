
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

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    ll N, M;
    cin >> N >> M;

    vector<ll> a(N);

    ll L = 1;
    REP(i, N) {
        cin >> a[i];
        L = lcm(L, a[i]);
    }

    // check if ans exists
    ll cnt;
    REP(i, N) {
        ll div = L / a[i];

        ll tmp = 0;
        while(div % 2 == 0) {
            tmp++;
            div >>= 1;
        }

        if (i == 0) {
            cnt = tmp;
            continue;
        }

        if (cnt != tmp) {
            print(0);
            return 0;
        }

        cnt = tmp;
    }

    print(ll(ceil(2 * M / L / double(2))));
}
