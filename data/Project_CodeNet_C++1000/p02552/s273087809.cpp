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
int x;
int main() {
	x = read();
	cout << (x == 1 ? 0 : 1) << '\n';
	return 0;
}