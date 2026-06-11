#include <bits/stdc++.h>
#define pb          emplace_back
#define ll          long long
#define fi          first
#define se          second
#define mp          make_pair

using namespace std;

typedef pair<int, int> pii;
const int N = 102;
const int logN = 17;

template<typename T> inline void Cin(T &x)
{
    char c;
    T sign = 1;
    x = 0;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') sign = -1;
    for (; c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    x *= sign;
}
template <typename T> inline void Out(T x) {if(x > 9) Out(x / 10); putchar(x % 10 + '0');}
template <typename T> inline void Cout(T x, char c) {if(x < 0) putchar('-'); x = abs(x); Out(x); putchar(c);}
template <typename T, typename... Args> inline void Cin(T& a, Args&... args) {Cin(a);Cin(args...);}
template <typename T, typename... Args> inline void Cout(T a, char c, Args... args) {Cout(a, c);Cout(args...);}

pii p[N], cur;
int n;
ll res = 0;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    #define Task        "test"
    if(fopen(Task".inp", "r")) {
        freopen(Task".inp", "r", stdin);
        freopen(Task".out", "w", stdout);
    }
    Cin(n);
    for(int i = 1; i <= n; ++i) Cin(p[i].fi, p[i].se);
    sort(p + 1, p + n + 1, [](const pii& x, const pii& y) {
            return atan2(x.fi, x.se) < atan2(y.fi, y.se);
         });
    for(int i = 1; i <= n; ++i) {
        cur = p[i]; res = max(res, 1ll * cur.fi * cur.fi + 1ll * cur.se * cur.se);
        for(int j = (i < n? i + 1: 1); j != i; j = (j < n? j + 1: 1)) {
            cur.fi += p[j].fi; cur.se += p[j].se;
            res = max(res, 1ll * cur.fi * cur.fi + 1ll * cur.se * cur.se);
        }
    }
    cout << fixed << setprecision(11);
    cout << sqrt((long double)res);
}
