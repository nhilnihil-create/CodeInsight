#include <iostream>
#include <cmath>
#define ll long long

using namespace std;

int main() {
    ll n;
    cin >> n;
    for (ll i = sqrtl(n) + 1; i > 0; i--) {
        if (n % i == 0) {
            cout << ((n / i) + i - 2);
            break;
        }
    }
}