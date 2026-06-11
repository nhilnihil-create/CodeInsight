#include <iostream>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    while (m--) {
        int a; cin >> a;
        n -= a;
        if (n < 0) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << n << endl;
}

