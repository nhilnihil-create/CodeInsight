#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define RREP(i, n) for (ll i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define RFOR(i, a, b) for (ll i = a; i >= (ll)(b); i--)
#define ALL(x) (x).begin(), (x).end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    for (auto a : v) os << a << ", ";
    os << "]";
    return os;
}

template <typename T1, typename T2>
ostream &operator<<(ostream &os, const map<T1, T2> &mp) {
    os << "[";
    for (auto a : mp) os << "{" << a.first << ":" << a.second << "}, ";
    os << "]";
    return os;
}

map<ll, int> prime_factor(ll n) {
    map<ll, int> ret;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret[i]++;
            n /= i;
        }
    }
    if (n != 1) ret[n] = 1;
    return ret;
}

int main() {
    ll A, B;
    cin >> A >> B;
    map<ll, int> ap, bp;
    ap = prime_factor(A);
    bp = prime_factor(B);

    ll ans = 0;
    for (auto p : ap) {
        if (bp.find(p.first) != bp.end()) ans++;
    }

    cout << ans + 1 << endl;

    return 0;
}