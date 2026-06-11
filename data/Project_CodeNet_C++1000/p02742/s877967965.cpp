#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    unsigned long long int H, W, a = 0, b = 0; cin >> H >> W;
    if (H % 2 == 0) a = H / 2;
    else a = H / 2 + 1;
    if (W % 2 == 0) b = W / 2;
    else b = W / 2 + 1;
    unsigned long long int x = H - a, y = W - b;
    if (W == 1 || H == 1) {
        printf("%d\n", 1);
        return 0;
    }
    unsigned long long int ans = (a * b) + (x * y);
    cout << ans << endl;
    return 0;

}
