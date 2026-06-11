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
map<pair<char, char>, ll> cnt;
int main() {
    ll n, m;
    cin >> n;
    cin >> m;
    vector<P> ab(n);
    REP(i, n) { cin >> ab[i].first >> ab[i].second; }
    sort(ab.begin(), ab.end());
    ll x = 0;
    ll ans = 0;
    priority_queue<ll> pq;
    rep(i, 1, m + 1) {
        while (x < n && i == ab[x].first) {
            pq.push(ab[x].second);
            x++;
        }
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << endl;
}