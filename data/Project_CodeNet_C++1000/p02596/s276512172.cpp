#include <math.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#define rep(inc, bgn, end) for (int inc = bgn; inc < end; ++inc)
#define repe(inc, bgn, end) for (int inc = bgn; inc <= end; ++inc)

using ll = long long;
using namespace std;

int main() {
    int k;
    cin >> k;

    if (k % 2 == 0 || k % 5 == 0) {
        cout << -1;
        return 0;
    }

    int cnt    = 1;
    ll num     = 7;
    bool isEnd = false;
    while (true) {
        if (num < k) {
        } else {
            num %= k;
            if (num == 0) {
                cout << cnt;
                return 0;
            }
        }
        // 後処理
        cnt++;
        num = num * 10 + 7;
    }
    return 0;
}
