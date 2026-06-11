#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int X;
    cin >> X;
    int S = X;
    for (int i = 1;; i++) {
        if (S % 360 == 0) {
            cout << i << endl;
            return 0;
        }
        S += X;
    }
}