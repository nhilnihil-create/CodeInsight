#include <iostream>
using namespace std;

int main() {
    int dec[10][10] = {}, len[10][10] = {};
    for (int a = 1; a < 10; a++)
        for (int b = 0; b < 10; b++) {
            int x = a, y = b;
            do {
                x += y;
                if (x < 10) { y = b; dec[a][b]++; }
                else { y = x % 10; x /= 10; }
                len[a][b]++;
            } while (x != a || y != b);
        }
    int m; cin >> m;
    long long ans = 0;
    int l = 0;
    while (m--) {
        long long d, c; cin >> d >> c;
        if (l == 0) { l = d; c--; }
        if (d == 0) { ans += c; continue; }
        if (c >= dec[l][d]+1) {
            ans += (c-1) / dec[l][d] * len[l][d];
            c = (c-1) %dec[l][d] + 1;
        }
        while (c--) {
            l += d;
            ans++;
            if (l >= 10) { l = l % 10 + l / 10; ans++; }
        }
    }
    cout << ans << endl;
}
