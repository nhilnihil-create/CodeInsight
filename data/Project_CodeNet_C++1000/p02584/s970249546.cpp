#include <bits/stdc++.h>
using namespace std;

int main() {
    long long X, K, D;
    cin >> X >> K >> D;
    X = abs(X);
    long long n = min(K, X / D);
    K -= n;
    X -= n * D;
    if(K % 2 == 0) {
        cout << X;
    } else {
        cout << abs(D - X);
    }
}