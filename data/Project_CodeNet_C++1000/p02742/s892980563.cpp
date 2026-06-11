#include <iostream>
#define int long long
using namespace std;

signed main() {
    int h,w;
    int high, low;
    int ans = 0;

    cin >> h >> w;
    if(h == 1 || w == 1){
        cout << 1;
    }else {
        low = w / 2;
        high = w - low;
        for (int i = 0; i < h; i++) {
            if (i % 2 == 0) ans += high;
            else ans += low;
        }
        cout << ans;
    }
    return 0;
}