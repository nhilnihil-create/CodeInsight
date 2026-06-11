#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    auto log10 = [](uint64_t n) {
        int log = 0;
        while (10 <= n) {
            ++log;
            n /= 10;
        }
        return log;
    };
    auto first = [](uint64_t n) {
        int last = 0;
        while (n) {
            last = n % 10;
            n /= 10;
        }
        return last;
    };

    int n; cin >> n;

    bool bad = false;
    uint64_t total = 1;
    while (n--) {
        uint64_t a; cin >> a;
        if (a == 0) {
            cout << 0 << endl;
            return 0;
        }

        if (18 <= log10(total) + log10(a) && 10 <= first(total) * first(a) || 1000000000000000000 < total * a) {
            bad = true;
        }

        /*if (18 < log10(total) + log10(a) || 1000000000000000000 < total * a) {
            bad = true;
        }*/

        total *= a;
    }

    if (bad) cout << -1 << endl;
    else cout << total << endl;
}

