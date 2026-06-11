#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long a, b, c, k;
    long sum = 0;
    cin >> a >> b >> c >> k;
    if (a > k) {
        cout << k;
        return 0;
    }
    sum += a;
    k = k - a;
    if (b > k) {
        cout << sum;
        return 0;
    }
    k = k - b;
    sum -= k;
    cout << sum;
}
