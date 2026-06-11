#include "bits/stdc++.h"

using namespace std;

void Main() {
    long long a, b, c;
    cin >> a >> b >> c;

    bool s = false;
    long long d = c - a - b;
    if (d > 0 && d * d > 4 * a * b) {
        s = true;
    }
    cout << (s ? "Yes" : "No") << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
