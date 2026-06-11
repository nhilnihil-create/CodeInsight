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
    int a[4] = {0,300000,200000,100000};
    int aa = read(), bb = read();
    int ans = 0;
    if (aa == 1 && bb == 1) {
        ans += 400000;
    }
    if (aa <= 3) {
        ans += a[aa];
    }
    if (bb <= 3) {
        ans += a[bb];
    }
    // ans += a[aa] + a[bb];
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