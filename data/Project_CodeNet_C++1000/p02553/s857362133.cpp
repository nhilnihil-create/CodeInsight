#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
inline int read() {
    int x = 0, fh = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-')
            fh = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = (x << 1) + (x << 3) + c - '0';
        c = getchar();
    }
    return x * fh;
}
LL a, b, c, d;
LL kmax(LL a, LL b, LL c, LL d) { return max(max(max(a, b), c), d); }
int main() {
	a = read(); b = read(); c = read(); d = read();
	cout << kmax(a * c, a * d, b * c, b * d);
	return 0;
}