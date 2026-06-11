#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    int64_t x; cin >> x;

    int64_t n = 100;
    int ans = 0;
    while (n < x) {
        n += n / 100;
        ++ans;
    }

    cout << ans << endl;
}

