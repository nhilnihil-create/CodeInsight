#include <bits/stdc++.h>

using namespace std;


constexpr int mod = 1000000007;

long long f(int x, int n) {
    long long counter = 1;
    for(int i = 0; i < n; i++) {
        counter *= x;
        counter %= mod;
    }
    return counter;
}

int main() {
    int n;
    cin >> n;
    long long ans = f(10, n) - f(9, n) - f(9, n) + f(8, n);
    ans %= mod;
    if(ans < 0) {
        ans += mod;
    }
    cout << ans << "\n";
    return 0;
}