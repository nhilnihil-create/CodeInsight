#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdint>
using namespace std;

int main() {
    int64_t n, k; cin >> n >> k;
    if (k < n) n -= k * (n / k);
    cout << min(n, abs(n - k)) << endl;
}

