#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
    int x;
    cin >> x;
    int total = 0;
    for (int i = 0; i <= 1000; ++i) {
        total += x;
        if (total % 360 == 0) {
            cout << i + 1 << endl;
            return 0;
        }
    }
}