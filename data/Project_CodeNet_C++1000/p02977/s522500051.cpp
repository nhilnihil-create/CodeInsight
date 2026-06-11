#include <algorithm>
#include <iostream>
#include <cstdio>
#define N 200005
using namespace std;

int n;

void con(int x, int y) {
    printf("%d %d\n", x, y);
}

int main() {
#ifdef whyqx
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif
    cin >> n;
    if (n == (n & (-n))) {
        puts("No");
        return 0;
    } else 
    puts("Yes");
    int m = n % 2 ? n : n - 1;
    con(2, 3), con(2 + n, 3 + n), con(1, 2), con(1, 3 + n), con(1 + n, 2 + n);
    for (int i = 4; i <= m; i += 2) {
        con(i, i + 1), con(i + n, i + 1 + n);
        con(1, i), con(1, i + 1 + n);
    }
    if (n % 2 == 0) {
        int tmp;
        for (int i = 30; i >= 1; --i)
            if ((1 << i) & n) {
                tmp = 1 << i;
                break;
            }
        int t = n ^ tmp ^ 1;
        con(tmp, n), con(t + n, n + n);
    }
    return 0;
}
