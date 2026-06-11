#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>
#include <random>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 10000000000;
const double PI = acos(-1);
const ll mod = 1000000007;

int main()
{
    int l, r;
    cin >> l >> r;

    // 2019の倍数を必ず選べる
    if ((r - l) >= 2018) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 2019;
    for (int i = l; i < r; i++) {
        for (int j = i + 1; j <= r; j++) {
            int m = (i % 2019) * (j % 2019);
            m %= 2019;
            ans = min(ans, m);
        }
    }
    cout << ans << endl;
    return 0;
}
