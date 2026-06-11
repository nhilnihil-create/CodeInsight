#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int A, B, K;
    cin >> A >> B >> K;
    long long int a, b;
    if(K <= A) {
        cout << A - K << " " << B << endl;
    } else if(K <= A + B) {
        cout << 0 << " " << B - K + A << endl;
    } else {
        cout << 0 << " " << 0 << endl;
    }
    return 0;
}