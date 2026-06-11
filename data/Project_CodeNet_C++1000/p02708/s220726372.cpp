#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    int64_t n, k; cin >> n >> k;
    int64_t ans = 0;

    while (k <= n + 1) {
        int64_t min = k * (k - 1) / 2;
        int64_t max = k * (2 * n - k + 1) / 2;
        ans = (ans + (max - min + 1)) % 1000000007;
        ++k;
    }

    cout << ans << endl;
}

