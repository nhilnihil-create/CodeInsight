#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, k;
    cin >> n >> k;
    long long x = n % k;
    long long y = abs(x - k);
    if (y < x) {
        cout << y;
    } else {
        cout << x;
    }
}
