#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define ddrep(i, n) for (int i = n; i > 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define ssrep(i, s, t) for (int i = s; i <= t; ++i)

#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#define chmax(x, y) (x = max(x, y))
#define chmin(x, y) (x = min(x, y))

using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vs = vector<string>;
using vvs = vector<vs>;
using ld = long double;

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "{";
    rep(i, (int)v.size()) {
        if (i)
            os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

template <typename T, size_t S> void printArray(const T (&array)[S]) {
    for (auto val : array)
        std::cout << val << ", ";
    std::cout << "\n";
}

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x%y);
}

const int MAX = 1e6 + 5;
vi isPrime(MAX);
void sieve() {
    rep(i, MAX) isPrime[i] = i;
    isPrime[0] = isPrime[1] = -1;
    for (int x = 2; x*x <= MAX; x++) {
        if (isPrime[x] != x) continue;
        for (int y = x; y < MAX; y += x) {
            isPrime[y] = x;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << std::setprecision(10);

    int n; std::cin >> n;
    vi a(n); rep(i, n) std::cin >> a[i];

    sieve();
    vi cnt(MAX);
    rep(i, n) {
        set<int> s;
        int x = a[i];
        while (x != 1) {
            s.insert(isPrime[x]);
            x /= isPrime[x];
        }
        for (int v : s) {
            cnt[v]++;
        }
    }
    bool ispare = true;
    rep(i, MAX) if (cnt[i] > 1) ispare = false;

    int gcdv = a[0];
    rep(i, n-1) {
        gcdv = gcd(gcdv, a[i+1]);
    }

    if (ispare) {
        std::cout << "pairwise coprime" << "\n";
    } else if (gcdv == 1) {
        std::cout << "setwise coprime" << "\n";
    } else {
        std::cout << "not coprime" << "\n";
    }
}
