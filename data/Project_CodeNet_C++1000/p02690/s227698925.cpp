#include <bits/stdc++.h>
using namespace std;

int main() {
    long long X;
    cin >> X;
    for (long long A = -200; A <= 200; ++A) {
        for (long long B = -200; B <= 200; ++B) {
            if (A*A*A*A*A - B*B*B*B*B == X) {
                cout << A << " " << B << endl;
                return 0;
            }
        }
    }
}