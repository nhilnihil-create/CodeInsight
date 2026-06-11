#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int64_t K, X;
    cin >> K >> X;
    if (500 * K >= X) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}