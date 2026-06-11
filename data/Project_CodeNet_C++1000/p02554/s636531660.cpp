#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1e9 + 7;

int n;

int main() {
    cin >> n;
    ll A = 1, B = 1, C = 1;
    for(int i = 1; i <= n; i++) {
        A = A * 10 % mod;
        B = B * 9 % mod;
        C = C * 8 % mod;
    }
    cout << (A - 2LL * B + C + 10LL * mod) % mod << '\n';
    return 0;
}
