#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;
long long pow(int x, int n);

signed main() {
    int n;
    long long ans;
    cin >> n;

    ans = (pow(10, n) - pow(9, n) - pow(9, n) + pow(8, n)) % MOD;

    cout << (ans + MOD) % MOD << endl; 

    return (0);
}

long long pow(int x, int n) {
    long long ans = 1;

    for ( int i = 0; i < n; i++ ) {
        ans = ans * x;

        ans = ans % MOD;
    }

    return (ans);
}