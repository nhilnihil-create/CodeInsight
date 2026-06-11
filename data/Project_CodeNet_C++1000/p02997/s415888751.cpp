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

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int maxp = (n - 1) * (n - 2) / 2;
    if (k > maxp) {
        printf("-1\n");
    } else {
        int diff = maxp - k;
        int e = (n - 1) + diff;
        printf("%d\n", e);
        for (int i = 2; i <= n; i++) {
            printf("%d %d\n", 1, i);
        }
        for (int i = 2; i <= n && diff > 0; i++) {
            for (int j = i + 1; j <= n && diff > 0; j++) {
                printf("%d %d\n", i, j);
                diff--;
            }
        }
    }
}
