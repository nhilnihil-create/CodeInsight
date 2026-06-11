#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    if (k > (n - 1) * (n - 2) / 2) {
        puts("-1");
    } else {
        int rem = (n - 1) * (n - 2) / 2 - k;
        cout << n - 1 + ((n - 1) * (n - 2) / 2 - k) << endl;
        for (int i = 2; i <= n; i++) {
            cout << "1 " << i << endl;
        }
        int a = 2, b = 3;
        while (rem--) {
            cout << a << ' ' << b << endl;
            b++;
            if (b > n) {
                a++;
                b = a + 1;
            }
        }
    }
}
