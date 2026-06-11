#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            cout << i + 1;
        }
    }
    return 0;
}
