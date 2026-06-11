#include <iostream>
using namespace std;

typedef unsigned long long ull;

static const ull MOD = 1000000007;

ull pow(ull x, ull n) {
    if (n == 0) return 1;

    ull ret = pow((x*x) % MOD, n/2);
    if (n % 2 != 0) {
        ret = ret*x % MOD;
    }

    return ret;
}

int main(void) {
    ull m, n;
    cin >> m >> n;

    ull ans = pow(m, n);

    cout << ans << endl;

    return 0;
}