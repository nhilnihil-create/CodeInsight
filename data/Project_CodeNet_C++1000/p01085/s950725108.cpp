#include <iostream>

using namespace std;

int main() {
    int p[201], ans, t;
    int m, n_min, n_max;

    while (cin >> m >> n_min >> n_max) {
        if (m == 0 && n_min == 0 && n_max == 0) { break; }

        for (int i = 0; i < m; i++) {
            cin >> p[i]; 
        }

        ans = 0; t = 0;

        for (int i = n_min; i <= n_max; i++) {
            if (t <= p[i-1] - p[i]) {
                ans = i;
                t = p[i-1] - p[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
