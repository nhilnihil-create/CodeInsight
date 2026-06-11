#include <iostream>
#include <iomanip>
#include <cstdint>
using namespace std;

int main() {
    cout << fixed << setprecision(9);

    int64_t w, h, x, y;
    cin >> w >> h >> x >> y;
    cout << w * h / 2.0 << ' ' << (!(w & 1) && !(h & 1) && w / 2 == x && h / 2 == y ? 1 : 0) << endl;
}

