#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
#include <stack>
#include <functional>

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define repp(i, m, n) for(int i = m, i##_len = (n); i < i##_len; ++i)
#define reprev(i, n) for(int i = (n-1LL); i >= 0; --i)
#define all(x) (x).begin(), (x).end()
template <class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template <class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> P;
typedef long double ld;

constexpr int MOD = 1000000007;

// + - * / ^
int mod(int a)
{
    int res = a % MOD;
    if(res < 0) {
        return res + MOD;
    }
    return res;
}
int mul_mod(int a, int b)
{
    ll res = ((ll)a * (ll)b) % MOD;
    return mod((int)res);
}
int pow_mod(int a, int b)
{
    ll res = 1;
    while (b > 0) {
        if(b & 1) {
            res = res * (ll)a % (ll)MOD;
        }
        a = mul_mod(a, a);
        b >>= 1;
    }
    return (int)res;
}
int inv_mod(int a)
{
    return pow_mod(a, MOD - 2);
}
int div_mod(int a, int b)
{
    return mul_mod(a, inv_mod(b));
}

// ! C
constexpr int FAC_MAX = 200001;
ll fac[FAC_MAX], finv[FAC_MAX], inv[FAC_MAX];
void com_init()
{
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < FAC_MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
ll com_mod(int a, int b){
    if (a < b) return 0;
    if (a < 0 || b < 0) return 0;
    return fac[a] * (finv[b] * finv[a - b] % MOD) % MOD;
}

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> g[n];
    rep (i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<P> dp(n);
    priority_queue<P> q;
    q.emplace(0, 0);
    dp[0].first = -1;
    while (!q.empty()) {
        P p = q.top(); q.pop();
        for (int i : g[p.second]) {
            if (dp[i].first == 0) {
                dp[i].first = p.second + 1;
                dp[i].second = p.first + 1;
                q.emplace(p.first + 1, i);
            }
        }
    }
    rep (i, n) eprintf("%d %d\n", dp[i].second, dp[i].first);
    sort(all(dp));
    int ans = k, now = k - 2;
    repp (i, 1, n) {
        if (dp[i].first != dp[i - 1].first) now = k - 2 + (dp[i].second == 1);
        else now--;
        ans = mul_mod(ans, now);
    }
    cout << ans << "\n";
    return 0;
}