#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int h, n;
    cin >> h >> n;
    vector<int> dp(h + 1, 1e9);
    dp[0] = 0;
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        rep(j, h+1) {
            int idx = min(j + a, h);
            dp[idx] = min(dp[idx], dp[j] + b);
        }
    }
    cout << dp[h] << endl;
    return 0;
}
