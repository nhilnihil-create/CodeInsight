#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int cnt = 0, tap = 1;
    for (int i = 0; i < 100; i++) {
        if (B <= tap) {
            cout << cnt << endl;
            return 0;
        }
        else {
            tap += A - 1;
            cnt++;
        }
    }
}
