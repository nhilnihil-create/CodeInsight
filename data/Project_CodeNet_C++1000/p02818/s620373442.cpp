#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll A, B, K;
    cin >> A >> B >> K;
    if(A > K) {
        cout << A - K << ' ' << B << endl;
    } else if(A + B > K) {
        cout << 0 << ' ' << A + B - K << endl;
    } else {
        cout << 0 << ' ' << 0 << endl;
    }
    

    return 0;
}