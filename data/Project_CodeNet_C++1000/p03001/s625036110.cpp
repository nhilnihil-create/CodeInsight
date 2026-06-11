#include <bits/stdc++.h>
using namespace std;

int main() {
    double W, H, x, y;
    cin >> W >> H >> x >> y;

    double max = W * H / 2;

    if (x == W / 2 && y == H / 2) {
        printf("%f 1\n", max);
    } else {
        printf("%f 0\n", max);
    }

    return 0;
}
