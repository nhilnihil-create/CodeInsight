#include <bits/stdc++.h>
using namespace std;

int main () {
    long long w, h, x, y;
    cin >> w >> h >> x >> y;

    if (x + x == w && y + y == h) {
        printf("%.10f %c\n", double(w) * double(h) / 2, '1');
    } else {
        printf("%.10f %c\n", double(w) * double(h) / 2, '0');
    }

}

