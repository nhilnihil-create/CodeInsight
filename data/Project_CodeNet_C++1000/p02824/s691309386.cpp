#include <algorithm>
#include <cstdio>
#define LL long long

using namespace std;

const int N = 1e5 + 5;

int n, m, v, p;
int d[N];

bool cmp(int a, int b) {
    return a > b;
}

bool check(int mid) {
    if (mid <= p) return 1;
    if (d[mid] + m < d[p]) return 0;
    if (v < p && d[mid] + m >= d[p]) return 1;
    LL ans = (LL)m * p;
    for (int i = n, j = v - p; i > mid && j; i--, j--) {
        ans += m;
    }
    LL ned = (LL)m * v - ans;
    int cd;
    for (int i = p; i < mid; ++i) {
        int x = min(m, max(0, d[mid] + m - d[i]));
        if (x > ned) x = ned;
        ned -= x;
        if (i == p) {
            cd = d[p] + x;
        }
    }
    return cd <= m + d[mid] && ned <= 0;
}

int main() {
    scanf("%d%d%d%d", &n, &m, &v, &p);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &d[i]);
    }
    sort(d + 1, d + n + 1, cmp);
    int l = 1, r = n + 1;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%d\n", l);
    return 0;
}