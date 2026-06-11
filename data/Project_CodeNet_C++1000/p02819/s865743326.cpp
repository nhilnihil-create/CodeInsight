#include <bits/stdc++.h>
using namespace std;

bool prime(int n) {
    if (n % 2 == 0)  return 0;
    int lim = sqrt(n);
    for (int i = 3; i <= lim; i+= 2) {
        if (n%i == 0) {
            return 0;
        }
    }
    return 1;
}

void solve () {
    int n;
    cin >> n;
    if (n == 2) {
        cout << 2;
        return;
    }
    n += (n % 2 == 0);
    while (1) {
        if (prime(n)) {
            cout << n;
            return;
        }
        n+=2;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
