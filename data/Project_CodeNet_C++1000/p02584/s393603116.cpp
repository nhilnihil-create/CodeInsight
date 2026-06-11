// Atcoder beginner round 175 C - Walking Takahashi

#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

void solve() {
    ll X, K ,D; 
    cin >> X >> K >> D;
    X = abs(X);
    if (X / D >= K)
        cout << X - K*D;
    else {
        K = K - X/D;
        X = X - (X /D) * D;
        if (K % 2 == 0) 
            cout << X;
        else 
            cout << abs(X - D);
    }
}

int main() {
    solve();
    return 0;
}