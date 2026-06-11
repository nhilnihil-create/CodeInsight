#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
long long dp[3030][3030] = { 0 };
pair<long long, long long> pa[3030];
int main() {
    long long n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        pa[i] = make_pair(a, b);
    }
    sort(pa, pa + n);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < t; j++) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j + pa[i - 1].first < t) {
                dp[i][j + pa[i - 1].first] = max(dp[i - 1][j + pa[i - 1].first], dp[i - 1][j] + pa[i - 1].second);
            }
        }
        long long now = dp[i - 1][t - 1] + pa[i - 1].second;
        if (ans < now) {
            ans = now;
        }
    }
    cout << ans << endl;
    return 0;
}
