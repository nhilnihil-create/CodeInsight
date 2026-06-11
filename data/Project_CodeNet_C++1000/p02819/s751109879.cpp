#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

bool is_prime(ll n) {
    if (n == 1) {
        return false;
    }
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ll x;
    cin >> x;

    while (!is_prime(x)) {
        x++;
    }
    cout << x << endl;
}