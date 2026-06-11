#include <bits/stdc++.h>
using namespace std;

int main() {
    long long H, W;
    cin >> H >> W;
    
    if (H == 1 || W == 1) {
        cout << 1 << endl;
        return 0;
    }

    long long ans = (H / 2) * (W / 2);
    ans += (H - H / 2) * (W - W / 2);
    cout << ans << endl;
    return 0;
}