#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i < 50000; i++) {
        double tmp = i * 1.08;
        if ((long long)tmp == n) {
            cout << i << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
    return 0;
}