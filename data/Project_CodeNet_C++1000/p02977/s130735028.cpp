
#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x, char ed = '\n') {
    static short st[30];short tp=0;
    if(x<0) putchar('-'),x=-x;
    do st[++tp]=x%10,x/=10; while(x);
    while(tp) putchar('0'|st[tp--]);
    putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

int n;
inline void Add(int x, int y, int t) {
    if (t) write(x + n, ' '), write(y + n);
    else write(x, ' '), write(y);
}
int main() {
    read(n); int lim = 1;
    while (lim <= n) {
        if (lim == n) return puts("No"), 0;
        lim <<= 1;
    }
    puts("Yes");
    for (int i = 2;i <= 3; i++)
        Add(i - 1, i, 0), Add(i - 1, i, 1);
    write(n + 1, ' '), write(3);
    for (int i = 4;i < n; i += 2) 
        Add(i, i + 1, 0), Add(i + 1, 1, 0), Add(1, i, 1), Add(i + 1, i, 1);
    if (!(n & 1)) {
        for (int i = 2;i <= n; i++) {
            int tt = n ^ i ^ 1;
            if (i == 3 || tt > n) continue;
            if (tt & 1) swap(tt, i);
            Add(i, n, 0), Add(tt, n, 1);
            return 0;
        }
        return 0;
    }
    return 0;
}
