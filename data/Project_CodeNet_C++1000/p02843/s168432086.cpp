#include "bits/stdc++.h"

using namespace std;

void Main() {
    int X;
    cin >> X;

    int last2digits = X % 100;
    for (int x1 = 0; x1 < 100; ++x1) {
        for (int x2 = 0; x2 < 50; ++x2) {
            for (int x3 = 0; x3 < 34; ++x3) {
                for (int x4 = 0; x4 < 25; ++x4) {
                    for (int x5 = 0; x5 < 20; ++x5) {
                        int s = 101 * x1 + 102 * x2 + 103 * x3 + 104 * x4 + 105 * x5;
                        if ((X - s) % 100 == 0 && s <= X) {
                            cout << 1 << endl;
                            return;
                        }
                    }
                }
            }
        }
    }
    cout << 0 << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
