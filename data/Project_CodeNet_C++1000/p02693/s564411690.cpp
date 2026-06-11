#include <bits/stdc++.h>

using namespace std;

int main() {
    int K, A, B;
    bool fg = false;
    cin >> K;
    cin >> A >> B;

    for (int i = A; i <= B; i++) {
        if (i % K == 0) {
            cout << "OK" << endl;
            fg = true;
            break;
        }
    }

    if (!fg)cout << "NG" << endl;


}
