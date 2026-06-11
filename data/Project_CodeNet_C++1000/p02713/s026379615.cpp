#include <iostream>
#include <memory>
#include <numeric>
#include <string>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using llint = long long int;
using namespace std;

llint gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int k;
    cin >> k;

    llint sum = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            for (int l = 1; l <= k; l++) {
                sum += gcd(gcd(i, j), l);
            }
        }
    }
    cout << sum << endl;
}

