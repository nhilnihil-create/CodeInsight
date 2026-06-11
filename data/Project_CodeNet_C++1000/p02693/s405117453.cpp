#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, a, b;
    cin >> k >> a >> b;
    for (int i = 0; i <= (b - a); i++) {
        if ((a+i) % k == 0) {
            cout << "OK";
            return 0;
        }
    }
    cout << "NG";
}
