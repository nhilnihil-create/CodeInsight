#include <bits/stdc++.h>
using namespace std;

template <typename T> T gcd(T m, T n) {
    return n == 0 ? abs(m) : gcd(n, m % n);
}
template <typename T> T lcm(T m, T n) { return abs(m / gcd(m, n) * n); }

int main() {
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                sum += gcd(i, gcd(j, k));
            }
        }
    }
    cout << sum << '\n';
    return 0;
}