#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    int64_t n; cin >> n;
    cout << (
        (n * (n + 1) / 2) -
        ((n / 3) * (n / 3 + 1) * 3 / 2) -
        ((n / 5) * (n / 5 + 1) * 5 / 2) +
        ((n / 15) * (n / 15 + 1) * 15 / 2)
    ) << endl;
}

