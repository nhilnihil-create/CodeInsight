#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

template <class T>
inline void read(T &x) {
    x = 0;
    int f = 0;
    char ch = getchar();
    while (!isdigit(ch))    { f |= ch == '-'; ch = getchar(); }
    while (isdigit(ch))     { x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar(); }
    x = f ? -x : x;
    return ;
}

typedef unsigned long long uLL;

const uLL k = 1e18;

uLL a[100010];
uLL s;
int T, n;
bool flag;

int main () {
        flag = true;
        read(n);
        s = 1;
        for (int i = 1; i <= n; ++i) {
            read(a[i]);
            if (!a[i]) {
                flag = false;
            }
        }
        if (!flag) {
            puts("0");
            return 0;
        }
        for (int i = 1; i <= n; ++i) {
            if (a[i] == 0) {
                s = 0;
                break;
            }
            if (a[i] <= k / s) {
                s *= a[i];
            } else {
                flag = false;
                break;
            }
        }
        printf("%lld\n", flag ? s : -1);
    return 0;
}