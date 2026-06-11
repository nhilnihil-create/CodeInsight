#include <iostream>

using namespace std;
typedef long long ll;

int main(void)
{
    ll X, K, D;

    cin >> X >> K >> D;

    ll ans = 0;
    X = abs(X);
    if (X == 0) {
        if (K % 2 == 0) {
            ans = 0;
        } else {
            ans = D;
        }
    } else {
        ll n = abs(X) / D;
        if (n >= K) {
            ans = X - K * D;
        } else {
            X -= n * D;
            K -= n;
            if (K % 2 == 0) {
                ans = abs(X);
            } else {
                ans = abs(X - D);
            }
        }
    } 
    cout << abs(ans) << endl;

    return 0;
}