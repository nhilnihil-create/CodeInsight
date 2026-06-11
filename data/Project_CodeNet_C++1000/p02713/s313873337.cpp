#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <numeric>
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
#define repeat(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()

int dp[201][201] = {0};
int mgcd(int a, int b) {
    if (dp[a][b] > 0) {
        return dp[a][b];
    }

    dp[a][b] = gcd(a, b);
    return gcd(a, b);
}

signed main() {
    int k;
    cin >> k;

    int ans = 0;
    repeat(a, k) {
        repeat(b, k) {
            repeat(c, k) {
                ans += mgcd(mgcd(a + 1, b + 1), c + 1);
            }
        }
    }

    cout << ans;
    
    return 0;
}