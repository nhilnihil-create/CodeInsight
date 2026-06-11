#pragma GCC optimize ("O3")
#pragma GCC target ("tune=native")
#pragma GCC target ("avx")

#include <cstdio>

int main() {

    int n; scanf("%d", &n);

    int ans[512] = {};
    for (int j = 1, j_end = n-1; j <= j_end; ++j) {
        for (int l = j & -j; l; ++ans[j-1]) l >>= 1;
    }
    for (int i = 0, i_end = n-2; i <= i_end; ++i) {
        for (int j = 0, j_end = n-2-i; j <= j_end; ++j) {
            printf("%d%c", ans[j], j == j_end ? '\n' : ' ');
        }
    }
    
}