#include <iostream>
#include <algorithm>
#include <cstdint>
using namespace std;

int main() {
    int64_t a, b, c, k; cin >> a >> b >> c >> k;

    int64_t sum = 0;

    sum += 1 * min(a, k);
    k -= a <= k ? a : k;
    k -= b <= k ? b : k;
    sum += -1 * min(c, k);

    cout << sum << endl;
}

