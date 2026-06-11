#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

inline int highbit(int x) {
    for (int i = 1048576; i; i >>= 1)
        if (x & i) return i;
    puts(" :) ");
} 

int main() {
#ifdef isLOCAL
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
#endif

    int n;
    cin >> n;
    if (n == (n & (-n))) return puts("No"), 0;
    puts("Yes");

    if (n & 1) {
        for (int i = 2; i <= n; ++i)
            printf("%d %d\n%d %d\n", 1, i, i, (i ^ 1) + n);
        cout << n + 1 << " " << n + 2 << endl;
    } else {
        for (int i = 2; i < n; ++i)
            printf("%d %d\n%d %d\n", 1, i, i, (i ^ 1) + n);
        cout << n + 1 << " " << n + 2 << endl;
        int a = highbit(n), b = n ^ a ^ 1;
        cout << a << " " << n << endl;
        cout << b << " " << n + n << endl;
    }

    return 0;
}
