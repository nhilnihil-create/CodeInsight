#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#if __cplusplus >= 201103L
#include <chrono>
using namespace std::chrono;
#endif
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#ifdef LOCAL
#define prln(x) (cout << #x << ' ' << x << endl)
#define pr(x) (cout << #x << ' ' << x << ' ' )
#define prv(x) (cout << x << ' ')
#else
#define prln(x) 
#define pr(x)
#define prv(x)
#endif
#define clr(x) memset((x), 0, sizeof((x)))
#define clr1(x) memset((x), -1, sizeof((x)))
#define endl "\n"
#define pi acos(-1)
#define rep(i, st, ed) for (int i = (st); i <= (ed); ++i)
#define rep0(i, st, ed) for (int i = (st); i < (ed); ++i)
#define per0(i, st, ed) for (int i = (st); i > ed; --i)
#define per(i, st, ed) for (int i = (st); i >= ed; --i)
#define chmin(a, b) (a = a > b ? b : a)
#define chmax(a, b) (a = a < b ? b : a)
template<class T> void _sf(T &x) {cin >> x;}
void _sf(int &x) {scanf("%d", &x);}
void _sf(ll &x) {scanf("%lld", &x);}
void _sf(double &x) {scanf("%lf", &x);}
void _sf(char &x) {scanf(" %c", &x);}
void _sf(char *x) {scanf("%s", x);}
void sf() {}
template <class T, class...U> void sf(T & head, U&... tail) { _sf(head); sf(tail...);}
template <class T> void out(const T &val) { cout << val << endl; }
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}


int main(){
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        #if __cplusplus >= 201103L
        auto start = steady_clock::now();
        #endif
    #endif
    int n, k;
    cin >> n >> k;
    pr(n);prln(k);
    vector<ll> h(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    ll dp[310][310];
    for (int i = 0; i < 310; ++i) {
        for (int j = 0; j < 310; ++j) {
            dp[i][j] = 1e18;
        }
    }
    dp[0][0] = 0;
    for (int j = 1; j <= n - k; ++j) {
        for (int i = 1; i <= n; ++i) {
            for (int k = 0; k < i; ++k) {
                chmin(dp[i][j], dp[k][j - 1] + max(0ll, h[i] - h[k]));
            }
        }
    }
    ll ans = 1e18;
    prln(ans);
    rep(i, 0, n) {
        chmin(ans, dp[i][n - k]);
    }
    out(ans);
    #ifdef LOCAL
        #if __cplusplus >= 201103L
        auto end = steady_clock::now();
        duration<double> time_span = duration_cast<duration<double>>(end - start);;
        printf("Total time: %.6fs\n", time_span.count());
        #endif
    #endif
    return 0;
}