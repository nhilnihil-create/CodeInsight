#include <bits/stdc++.h>
using namespace std;

int main(void) {
    double n;
    cin >> n;
    for (double co = 1; co <= n; co++) {
        if (floor(co * 1.08) == n) {
            cout << co << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
    return 0;
}