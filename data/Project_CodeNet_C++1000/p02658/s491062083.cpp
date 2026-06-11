#include <iostream>

using namespace std;

int main() {
    int n;  cin >> n;
    long long *a = new long long[n], inf = 1e18;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            cout << 0 << endl;
            return 0;
        }
    }

    long long ans = 1;
    for (int i = 0; i < n; i++) {
        if (ans > inf/a[i]) {
            cout << -1 << endl;
            return 0;
        }
        else {
            ans *= a[i];
        }
    }
    cout << ((ans > inf) ? -1 : ans) << endl;
    return 0;
}