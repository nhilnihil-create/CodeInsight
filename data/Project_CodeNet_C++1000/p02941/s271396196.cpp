#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

int n;
int a[200005];
int res[200005];

ll ans = 0;

int fix(int A)
{
    if (A <= 0) A += n;
    if (A > n) A -= n;
    return A;
}

bool ishigh(int pos)
{
    return a[pos] > a[fix(pos-1)] + a[fix(pos+1)];
}

int main()
{
    scanf("%d", &n);
    queue<int> que;
    for (int i = 1; i <= n; i++) scanf("%d", res + i);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    for (int i = 1; i <= n; i++) {
        if (ishigh(i)) que.push(i);
    }
    while (!que.empty()) {
        int pos = que.front(); que.pop();
        int around = a[fix(pos-1)] + a[fix(pos+1)];
        //debug("%d", pos);
        if (res[pos] > (a[pos] % around)) {
            if (a[pos] < res[pos] || (a[pos] - res[pos]) % around || a[fix(pos+1)] != res[fix(pos+1)]
                || a[fix(pos-1)] != res[fix(pos-1)]) {
                printf("-1"); return 0;
            } else {
                ans += (ll)((a[pos] - res[pos]) / around);
                a[pos] = res[pos];
            }
        } else {
            ans += (ll)(a[pos] / around); a[pos] %= around;
        }
        if (ishigh(fix(pos-1))) que.push(fix(pos-1));
        if (ishigh(fix(pos+1))) que.push(fix(pos+1));
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] != res[i]) {
            printf("-1"); return 0;
        }
    }
    printf("%lld", ans);
    return 0;
}
