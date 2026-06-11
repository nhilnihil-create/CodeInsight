#include <iostream>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define Rep(i, s, n) for (int i = (int)s; i < (int)n; i++)

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int w[110];
    rep(i, n) {
        cin >> w[i];
    }

    int min = 1000000;
    rep(i, n) {
        int g1 = 0, g2 = 0;
        rep(j, n) {
            if (j <= i) g1 += w[j];
            else g2+= w[j];
        }
        g2 -= g1;
        if (g2 < 0) g2 = -g2;
        if (min > g2) min = g2;
    }
    cout << min << endl;
}