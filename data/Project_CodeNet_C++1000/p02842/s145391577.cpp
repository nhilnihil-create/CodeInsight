#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (double x = 0; x <= 50000; x++) {
        if ((int)(x * 1.08) == n) {
            cout << (int)x << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
    return 0;
}