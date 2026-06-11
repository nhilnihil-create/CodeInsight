#include "bits/stdc++.h"

using namespace std;

void Main() {
    long long H;
    cin >> H;

    long long ans = 1;
    while (H > 0) {
        H /= 2;
        ans *= 2;
    }
    ans -= 1;
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
