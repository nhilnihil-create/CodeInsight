#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int k, q;
    cin >> k >> q;
    vector<long> d(k);
    for (int i = 0; i < k; i++) {
        cin >> d[i];
    }
    for (int tt = 0; tt < q; tt++) {
        long n, x, m;
        cin >> n >> x >> m;
        x %= m;
        long res = n - 1;
        long s = 0;
        for (int i = 0; i < k; i++) {
//          i + (q - 1) * k <= n - 2
//          q <= (n - 2 - i) / k + 1

            int q = (n - 2 - i + k) / k;
            s += (q * (d[i] % m));

//            cout << q << "\n";

            if (d[i] % m == 0) {
                res -= q;
            }
        }
        long last = x + s;
//        cout << res << " " << last << "\n";

        res -= last / m;
        cout << res << "\n";
    }

    return 0;
}