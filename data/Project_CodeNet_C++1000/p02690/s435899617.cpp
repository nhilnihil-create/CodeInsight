#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, A, B;
    cin >> x;
    for (long long a = 0; a <= 119; a++) {
        for (long long b = -119; b <= 119; b++)
        if (pow(a, 5) - pow(b, 5) == x) {
            A = a, B = b;
            break;
        }
    }
    cout << A << " " << B << endl;
}