#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n], sum = 0, result = 1;
    for (int i = 0; cin >> a[i]; i++) {
        sum += a[i];
    }
    auto solve = [&](int num) {
        int r[n], suffix[n + 1];
        for (int i = 0; i < n; i++) {
            r[i] = a[i] % num;
        }
        sort(r, r + n);
        suffix[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + num - r[i];
        }
        for (int prefix = 0, i = 0; i < n; i++) {
            prefix += r[i];
            if (prefix == suffix[i + 1] && prefix <= k) {
                return true;
            }
        }
        return false;
    };
    for (int i = 1; i * i <= sum; i++) {
        if (sum % i == 0) {
            if (solve(i)) {
                result = max(result, i);
            }
            if (solve(sum / i)) {
                result = max(result, sum / i);
            }
        }
    }
    cout << result;
    return 0;
}
