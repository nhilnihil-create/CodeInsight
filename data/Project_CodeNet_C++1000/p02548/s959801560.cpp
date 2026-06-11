#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int32_t main() {
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i < n; ++i) {
        int cnt = (n - 1) / i;
        if (cnt > 0) {
            ans += cnt;
        }
    }
    cout << ans;
}
