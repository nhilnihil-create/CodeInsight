#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int w, h, x, y; cin >> w >> h >> x >> y;
    if (w == (Int)2* x && h == (Int)2 * y)
        printf("%.10f %d", (double)w*h/2.0, 1);
    else
        printf("%.10f %d", (double)w*h/2.0, 0);
}