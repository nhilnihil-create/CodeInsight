#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;
    for (double i = 1; i <= 1250; i++) {
        if (floor(i * 0.08) == a && floor(i * 0.1) == b) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}