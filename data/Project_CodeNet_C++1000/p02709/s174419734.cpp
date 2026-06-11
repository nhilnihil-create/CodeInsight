#include <bits/stdc++.h>

using ll = long long;
const int maxn = 2e3 + 3;

int n, a[maxn], o[maxn];
ll d[maxn][maxn];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    std::iota(o + 1, o + n + 1, 1);
    std::sort(o + 1, o + n + 1, [] (int i, int j) {
        return a[i] > a[j];
    });
    for(int t = 1; t <= n; ++t) {
        int i = o[t];
        ll u = a[i];
        for(int j = 0; j <= t; ++j) {
            int k = n - (t - j) + 1;
            if(j < t)
                d[t][j] = std::max(d[t][j], d[t - 1][j] + std::abs(i - k) * u);
            if(j)
                d[t][j] = std::max(d[t][j], d[t - 1][j - 1] + std::abs(i - j) * u);
        }
    }
    printf("%lld\n", *std::max_element(d[n], d[n] + n + 1));
    return 0;
}