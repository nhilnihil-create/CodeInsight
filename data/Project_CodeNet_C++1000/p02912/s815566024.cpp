#include <bits/stdc++.h>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;
template <typename A, size_t N, typename T> void Fill(A (&array)[N], const T& val) {
    std::fill((T*)array, (T*)(array + N), val);
}
// long long mod = 998244353;
#define REP(i, n) for (long long i = 0; i < (n); i++)
#define rep(i, a, n) for (long long i = a; i < (n); i++)
typedef long long ll;
typedef pair<ll, ll> P;
long long mod = 1000000007;
long long modpow(long long m, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2);
        return t * t % mod;
    } else {
        return modpow(m, n - 1) * m % mod;
    }
}
long long power(long long m, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2);
        return t * t;
    } else {
        return modpow(m, n - 1) * m;
    }
}

long long moddiv(long long a, long long b) { return (a * modpow(b, mod - 2)) % mod; }

const ll INF = 1LL << 60;

string change_binary(long long a) {
    string ret;
    for (int i = 31; i >= 0; i--) {
        ret += (a >> i & 1) + '0';
    }
    return ret;
}

ll nCkmod(ll n, ll k) {
    ll denomi = 1;
    for (int i = n; i > n - k; i--) {
        denomi *= i;
        denomi %= mod;
    }
    ll numera = 1;
    REP(i, k) {
        numera *= (i + 1);
        numera %= mod;
    }
    return moddiv(denomi, numera);
}
vector<vector<ll>> graph;
vector<ll> as;
map<P, ll> number;
ll rmemo[101][300001];
ll memo[101][300001];
ll func(string x, ll pc) {
    ll nowmod = 1;
    ll ret = x[0] - '0';
    rep(i, 1, x.size()) {
        nowmod = (nowmod * 2) % pc;
        if (x[i] == '1') {
            ret += nowmod;
            ret %= pc;
        }
    }
    return ret;
}
int main() {
    ll n, m;
    cin >> n >> m;
    priority_queue<ll> as;
    REP(i, n) {
        int t;
        cin >> t;
        as.push(t);
    }
    ll cur = 0;
    while (m > 0) {
        int k = as.top() / 2;
        as.pop();
        as.push(k);
        m--;
    }
    ll ans = 0;
    while (!as.empty()) {
        ans += as.top();
        as.pop();
    }
    cout << ans << endl;
}