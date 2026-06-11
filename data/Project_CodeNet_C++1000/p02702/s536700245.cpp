
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

#define debug(x) (cout << # x ": " << x << endl)
#define int long long int
#define repeat(n) for (int i = 0; i < n; ++i)
#define repeat2(n) for (int j = 0; j < n; ++j)
#define all(x) (x).begin(), (x).end()

#define MAX_SIZE (100001)

signed main() {
    string s;
    cin >> s;

    int n = 1;
    int x = 0;
    int cnt = 0;
    int dp[2019];
    memset(dp, 0, sizeof(int) * 2019);
    ++dp[0];
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        x = (x + (*it - '0') * n) % 2019;
        n = n * 10 % 2019;
        ++dp[x];
    }

    int ans = 0;
    repeat(2019) {
        ans += (dp[i] - 1) * dp[i] / 2;
    }

    cout << ans;
    
    return 0;
}
