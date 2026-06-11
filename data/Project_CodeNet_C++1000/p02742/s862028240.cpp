#include <iostream>
using namespace std;

int main() {
    long long H, W; cin >> H >> W;
    long long ans = H * W / 2 + (H%2 & W%2);
    if (H == 1 || W == 1) ans = 1;
    cout << ans << endl;
}