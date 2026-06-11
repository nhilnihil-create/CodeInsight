#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    long long mod = pow(10, 9) + 7;
    long long x = 1, y = 1, z = 1;
    for (int i=0; i<n; i++) {
        x = x * 10 % mod;
        y = y * 9 % mod;
        z = z * 8 % mod;
    }
    long long ans = (x - 2*y + z + 2*mod) % mod;
    cout << ans << endl; 
}