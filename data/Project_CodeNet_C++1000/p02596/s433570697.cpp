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

    ll value = 7;

    if (k % 2 == 0 | k % 5 == 0) {
        cout << -1;
        return 0;
    }

    int cnt = 0;
    while (true) {
        cnt++;
        value %= k;
        if (value == 0) {
            break;
        }
        value = value * 10 + 7;
    }

    cout << cnt;

    return 0;
}
