#include <bits/stdc++.h>

using namespace std;

int main() {
    long long x, k, d;
    cin >> x >> k >> d;
    if (x < 0) x = -x;
    long long temp;
  
    if (x % d == 0) temp = x / d;
    else temp = x / d + 1;
    if (k < temp) {
        printf("%lld\n", x - k * d);
        return 0;
    }
    k -= temp;
    x -= (temp * d);
    if (k % 2 == 0) printf("%lld\n", abs(x));
    else {
        printf("%lld\n", abs(x + d));
    }
    return 0;
}