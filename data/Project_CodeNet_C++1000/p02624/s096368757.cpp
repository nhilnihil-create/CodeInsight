#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
using ll = long long;

int f(int x) { // 整数kの約数の個数
    int r = 1;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            int cnt = 1;
            while (x % i == 0) {
                x /= i;
                cnt++;
            }
            r *= cnt;
        }
    }
    if (x != 1) {
        r *= 2;
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    ll sum = 0;
    // for (ll i = 1; i <= n; i++) {
    //     sum += i * f(i);
    // }
    // cout << sum << endl;
    for (ll i = 1; i <= n; i++) {
        sum += (1 + n / i) * (n / i) / 2 * i;
    }
    cout << sum << endl;
}