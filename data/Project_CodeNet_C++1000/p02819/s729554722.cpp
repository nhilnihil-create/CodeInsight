#include <bits/stdc++.h>
using namespace std;

// 
int main() {
    int X;
    cin >> X;
    vector<bool> primeNumbers(X * 2, true);
    for (int i = 2; i < X; i++) {
        if (!primeNumbers[i]) continue;
        int j = 2;
        int result = i;
        while (result < X * 2) {
            primeNumbers[result] = false;
            // cout << result << endl;  // debug
            j++;
            result = i * j;
        }
    }
    // debug
    // for (int i = 2; i < X * 2; i++) {
    //     cout << i << ":" << primeNumbers[i] << endl;
    // }
    for (int i = X; i < X * 2; i++) {
        if (primeNumbers[i]) {
            cout << i;
            return 0;
        }
    }
}
