#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main () {
    int n, m;
    while (cin >> n >> m, n | m) {
        vector<pair<int, int> > dp;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int d, p;
            cin >> d >> p;
            dp.push_back(make_pair(d, p));
            sum += d * p;
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = n - 1; j > i; j--) {
                if (dp[j].second > dp[j-1].second
                    || (dp[j].second == dp[j-1].second && dp[j].first < dp[j-1].first)) {
                    swap(dp[j], dp[j-1]);
                }
            }
        }

        int i = 0;
        while (m > 0 && i < n) {
            if (m >= dp[i].first) {
                m -= dp[i].first;
                i++;
            } else {
                dp[i].first -= m;
                break;
            }
        }

        int result = 0;
        for ( ; i < n; i++) {
            result += dp[i].first * dp[i].second;
        }
        cout << result << endl;
    }
}