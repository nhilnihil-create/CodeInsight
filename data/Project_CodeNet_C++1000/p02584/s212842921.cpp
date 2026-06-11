#include <iostream>

using namespace std;
typedef long long ll;

int main(void)
{
    ll X, K, D;

    cin >> X >> K >> D;

    ll ans = 0;

    if (X == 0) {
        if (K % 2 == 0) {
            ans = 0;
        } else {
            ans = D;
        }
    } else {
        ll m = 1;
        if (X < 0) {
            m = -1;
        }
        ll n = abs(X) / D;
        if (n >= K) {
            ans = X - m * K * D;
        } else {
            X = X - m * n * D;
            K -= n;
            if (X <= abs(X - m * D)) {
                if (K % 2 == 0) {
                    ans = abs(X);
                } else {
                    ans = abs(X - m * D);
                }
            } else {
                if (K % 2 == 0) {
                    ans = abs(X);
                } else {
                    ans = abs(X - m * D);
                }
            }
        }
    } 
    cout << abs(ans) << endl;

    return 0;
}