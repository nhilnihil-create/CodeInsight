#include "bits/stdc++.h"

using namespace std;

void Main() {
    long long H, W;
    cin >> H >> W;

    if (H == 1 || W == 1) {
        cout << 1 << endl;
        return;
    }

    long long ans = 0;
    if (W % 2 == 0) {
        ans = H * (W / 2);
    }
    else {
        if (H % 2 == 0) {
            ans = W * (H / 2);
        }
        else {
            ans = W * (H - 1) / 2;
            ans += (W + 1) / 2;
        }
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
