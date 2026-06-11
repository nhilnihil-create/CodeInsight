#include <bits/stdc++.h>
using namespace std;

int main() {
    long long T1, T2, A1, A2, B1, B2;
    cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
    long long A = A1 - B1, B = A2 - B2;
    if(A < 0) { A = -A; B = -B;}

    if(A * T1 + B * T2 > 0) {
        cout << 0 << endl;
    } else if(A * T1 + B * T2 == 0) {
        cout << "infinity\n";
    } else {
        long long a = A * T1, b = (A * T1 + B * T2) * (-1);
        if(a % b == 0) cout << 2 * (a / b) << endl;
        else cout << 2 * (a / b) + 1 << endl;
    }
}