#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll X, K, D; cin >> X >> K >> D;
    X = abs(X);
    if (X / D > K) cout << X - K * D << endl;
    else {
        K -= X / D;
        if (K % 2) cout << D - (X - X / D * D) << endl;
        else cout << X - X / D * D << endl;
    }
}