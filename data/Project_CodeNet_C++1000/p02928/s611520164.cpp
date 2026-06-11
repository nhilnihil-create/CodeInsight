#include <stdio.h>

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x) {
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x) {
    int f = 0;
    cerr << '{';
    for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}
#ifdef LOCAL
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end());
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

typedef long long ll;
ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    map<ll, ll> m;
    REP(i, N) { m[A[i]]++; }

    vector<ll> smaller(2010);
    REP(i, 2010) { smaller[i + 1] = m[i] + smaller[i]; }

    debug(smaller);
    ll ans = 0;
    REP(i, N) {
        ans += smaller[A[i]];
        ans = ans % MOD;
    }
    debug("1", ans);

    ans = ans * ((K*(K-1)/2) % MOD) % MOD;

    ll in_count = 0;
    // A内の転倒数の計算
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A.at(i) > A.at(j)) {
                in_count++;
            }
        }
    }
    ans = (ans + (in_count * K)) % MOD;
    cout << ans  << endl;

    return 0;
}
