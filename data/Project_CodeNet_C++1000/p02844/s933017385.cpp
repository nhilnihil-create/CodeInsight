#include <bits/stdc++.h>
using namespace std;

long N, ans;
string S;

int main(void) {

    cin >> N >> S;

    for (long pin = 0; pin <= 999; pin++) {
        long x, y, z;
        z = pin % 10; 
        y = ((pin - z) % 100) / 10;
        x = (pin - 10*y - z) / 100;

        bool f, g, h;
        f = g = h = false;
        for (auto e: S) {
            if (!f && !g && !h) {
                if ((e - '0') == x) {
                    f = true;
                }
            }
            else if (f && !g && !h) {
                if ((e - '0') == y) {
                    g = true;
                }
            }
            else if (f && g && !h) {
                if ((e - '0') == z) {
                    h = true;
                }
            }
        }

        if (f && g && h) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;

}