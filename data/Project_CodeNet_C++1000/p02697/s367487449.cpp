#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
constexpr ll M = 1e9 + 7;
inline ll sum_1(const ll n) { return ((n * (n + 1)) / 2) % M; }
inline ll sum_2(const ll n) { return ((n * (n + 1) * (2 * n + 1)) / 6) % M; }
inline ll sum_3(const ll n) { return (((n * (n + 1)) / 2) % M * ((n * (n + 1)) / 2) % M) % M; }
inline ll sum_1(const ll i, const ll j) { return (sum_1(j) - sum_1(i - 1) + M) % M; }
inline ll sum_2(const ll i, const ll j) { return (sum_2(j) - sum_2(i - 1) + M) % M; }
inline ll sum_3(const ll i, const ll j) { return (sum_3(j) - sum_3(i - 1) + M) % M; }

ll pow_f(ll b, ll e) {
    ll ans = 1;
    b = b % M;
    while (e) {
        if (e&1) {
            ans = (ans * b) % M;
        }
        b = (b * b) % M;
        e >>= 1;
    }
    return ans;
}

ll nCr(ll n, ll r) {
    if (r > n || n < 0 || r < 0) { return 0; }
    if (n == r || r == 0) { return 1; }
    r = min(r, n-r);
    ll ans = 1;
    for (ll i = 1; i <= r; ++i) {
        ans = (ans * (n-i+1))/(i); 
    }
    return ans;
}

ll nCr(tuple<ll,ll> t) {
    auto n = get<0>(t);
    auto k = get<1>(t);
    return nCr(n+k-1, k);
}

template<typename T>
void print(T v) {
    cout << v << " ";
}

template<typename T>
void print(vector<T> v) {
    for (auto &i : v) {
        print(i);
    }
    cout << endl;
}

void solve() {
    /**
     * 
     * 2*M + 1 <= N
     */ 

    ll n, m;
    cin >> n >> m;
    //start with biggest m diff
    for (ll i = 0; i < ceil(m/2.); ++i) {
        cout << i+1 << " " << m-i+1 << endl;
    }
    for (ll i = 0; i < m-ceil(m/2.); ++i) {
        cout << i+m+2 << " " << 2*m+1-i << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    #ifdef D_LOCAL
        freopen("in.in", "r", stdin);
        freopen("out.out", "w", stdout);
    #endif

    solve();

    return 0;
}