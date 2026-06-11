#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

using LL = long long;

int main() {
    LL a, b;
    cin >> a >> b;
    LL ans = 1;
    for (LL i = 2; i <= min(1000000ll, min(a, b)); i++) {
        if (a % i == 0 && b % i == 0) {
            ans++;
            while (a % i == 0 && b % i == 0) {
                a /= i;
                b /= i;
            }
        }
    }
    if (gcd(a, b) != 1) {
        ans++;
    }
    cout << ans << endl;
    return 0;
}
