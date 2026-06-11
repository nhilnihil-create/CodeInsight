#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <complex>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處

int s[2005], t[2005];

const LL M = (LL)1e9 + 7;

// r_fix[i][j] = 以 s 的第 i 個、 t 的第 j 個元素爲最右所構成的共同子串列數量
LL r_fix[2005][2005];
LL s_pre_t_fix[2005][2005];
LL s_fix_t_pre[2005][2005];
LL total[2005][2005];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &t[i]);
    }

    // 初始化
    // for (int i = 0; i <= n; i++) {
    //     total[i][0] = 1;
    // }
    // for (int i = 0; i <= m; i++) {
    //     total[0][i] = 1;
    // }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // r_fix;
            if (s[i] == t[j]) {
                r_fix[i][j] = (total[i - 1][j - 1] + 1) % M;
            } else {
                r_fix[i][j] = 0;
            }
            s_fix_t_pre[i][j] = (s_fix_t_pre[i][j - 1] + r_fix[i][j]) % M;

            total[i][j] = (total[i - 1][j] + s_fix_t_pre[i][j]) % M;
        }
    }
    printf("%lld\n", total[n][m] + 1);
}
