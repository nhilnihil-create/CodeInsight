#include <bits/stdc++.h>
#define R register
#define ll long long
#define mp make_pair
#define pii pair<int, int>
using namespace std;

ll t1, t2, a1, a2, b1, b2, ans;

template <class T>
inline void read(T &x) {
    x = 0;
    char ch = getchar(), w = 0;
    while (!isdigit(ch)) w = ch == '-', ch = getchar();
    while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    x = w ? -x : x;
    return;
}

int main() {
    read(t1), read(t2), read(a1), read(a2), read(b1), read(b2);
    ll sa = t1 * a1 + t2 * a2, sb = t1 * b1 + t2 * b2;
    if (sa == sb) return printf("infinity\n"), 0;
    if (sa > sb) swap(sa, sb), swap(a1, b1), swap(a2, b2);
    if (a1 < b1) return printf("0\n"), 0;
    printf("%lld\n", t1 * (a1 - b1) / (sb - sa) * 2 + (t1 * (a1 - b1) % (sb - sa) != 0));
    return 0;
}