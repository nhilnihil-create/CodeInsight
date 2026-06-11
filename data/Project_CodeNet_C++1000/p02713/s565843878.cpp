#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (a%b == 0) return b;
    else return gcd(b, a%b);
}

int main(int argc, char const *argv[]) {
    int k;
    cin >> k;

    int sum = 0;
    for (size_t i = 1; i <= k; i++) {
        for (size_t j = 1; j <= k; j++) {
            for (size_t m = 1; m <= k; m++) {
                sum += gcd(gcd(i, j), m);
            }
        }
    }

    cout << sum << endl;
    return 0;
}
