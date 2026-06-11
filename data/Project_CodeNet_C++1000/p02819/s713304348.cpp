#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
    if (n < 2) {
        return false;
    } else if (n == 2) {
        return true;
    } else if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int x;
    cin >> x;
    for (int i = x; i <= 1000003; i++) {
        if (is_prime(i)) {
            cout << i << endl;
            break;
        }
    }
}