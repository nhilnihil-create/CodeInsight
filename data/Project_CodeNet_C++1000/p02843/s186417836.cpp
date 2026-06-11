#include <bits/stdc++.h>
using namespace std;

int main() {
    int x;
    cin >> x;

    int res = 0;
    for (int i = 1; i <= x/100; i++) {
        if (100*i <= x && x <= 105*i) res = 1;
    }

    cout << res << endl;

    return 0;
}
