#include <iostream>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

ll modPow(ll m, ll n) {
    if (n == 0) return 1; 
    if (n % 2) return m * modPow(m, n-1) % MOD;
    else modPow(m * m % MOD, n / 2);
}

int main() {
    ll m, n; cin >> m >> n;
    cout << modPow(m, n) << endl; 
}
