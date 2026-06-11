#include <bits/stdc++.h>

using namespace std;

#define rep(x,a,b)         for(int x = a; x < b; x++)
#define per(x,a,b)         for(int x = a; x >= b; x--)
#define all(container)     (container).begin(), container.end()
#define rall(container)    (container).rbegin(), container.rend()
#define sz(container)      (int) (container).size()
#define pb                 push_back
#define eb                 emplace_back
#define fi                 first
#define sc                 second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template<class T> bool smin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool smax(T &a, T b) { return a < b ? (a = b, true) : false; }

#ifdef LOCAL_DEFINE
    #include "DEBUG.hpp"
#else
    #define debug(...) 0
#endif
const int maxn = 1100;
char s1[maxn], s2[maxn];

int main(void)
{
    scanf("%s%s", s1, s2);
    int n = strlen(s1), m = strlen(s2);
    int ans = INT_MAX;
    for(int i = 0; i + m - 1 < n; i++) {
        int cnt = 0;
        rep(j, 0, m) if(s2[j] != s1[i + j]) ++cnt;
        smin(ans, cnt);
    }
    printf("%d\n", ans);
    return 0;
}