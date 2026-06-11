#include <algorithm>
#include <bitset>
#include <climits>
#include <complex>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <tuple>
#include <type_traits>
#include <vector>

#include <stdio.h>

using ll = long long;
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int h, n;
    cin >> h >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    vector<int> dp(20005, INT_MAX);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= h; j++) {
            if (j < a[i]) {
                dp[j] = min(dp[j], b[i]);
            } else {
                dp[j] = min(dp[j], dp[j - a[i]] + b[i]);
            }
        }
    }
    cout << dp[h] << endl;

    return 0;
}
