#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second

using vint = vector<int>;
using pint = pair<int, int>;
using vpint = vector<pint>;

template <typename A, typename B>
inline void chmin(A& a, B b) {
    if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A& a, B b) {
    if (a < b) a = b;
}

template <class A, class B>
ostream& operator<<(ostream& ost, const pair<A, B>& p) {
    ost << "{" << p.first << "," << p.second << "}";
    return ost;
}

template <class T>
ostream& operator<<(ostream& ost, const vector<T>& v) {
    ost << "{";
    for (int i = 0; i < v.size(); i++) {
        if (i) ost << ",";
        ost << v[i];
    }
    ost << "}";
    return ost;
}

inline int topbit(unsigned long long x) {
    return x ? 63 - __builtin_clzll(x) : -1;
}

inline int popcount(unsigned long long x) {
    return __builtin_popcountll(x);
}

inline int parity(unsigned long long x) {
    return __builtin_parity(x);
}

long long gcd(long long a, long long b) {
    while (b) {
        swap(a %= b, b);
    }
    return a;
}
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b;
}

const int LIM = 1000000;
bool isprime[LIM + 1];
vint facts[LIM + 1];

signed main() {
    fill_n(isprime, LIM + 1, true);
    isprime[0] = isprime[1] = false;
    for (int i = 2; i <= LIM; i++) {
        if (!isprime[i]) continue;
        for (int j = i; j <= LIM; j += i) {
            facts[j].pb(i);
            if (i != j) isprime[j] = false;
        }
    }

    int N;
    cin >> N;
    vint A(N);
    rep(i, N) cin >> A[i];

    int g = 0;
    rep(i, N) g = gcd(g, A[i]);
    if (g != 1) {
        cout << "not coprime" << endl;
        return 0;
    }

    set<int> s;
    rep(i, N) {
        for (auto f : facts[A[i]]) {
            if (s.find(f) != s.end()) {
                cout << "setwise coprime" << endl;
                return 0;
            }
            s.insert(f);
        }
    }

    cout << "pairwise coprime" << endl;
    return 0;
}