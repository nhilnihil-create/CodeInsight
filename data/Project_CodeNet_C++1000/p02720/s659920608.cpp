#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;
const int mod = 1e9 + 7;

int check(string s) {
    int n = s.size();
    int dp[n][10][2];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][j][0] = dp[i][j][1] = 0;
        }
    }
    for (int j = 0; j < 10; j++) {
        if (j < s[0] - '0') dp[0][j][1] = 1;
        if (j == s[0] - '0') dp[0][j][0] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == s[i] - '0') {
                dp[i][j][0] = (j > 0 ? dp[i - 1][j - 1][0] : 0) + (j < 9 ? dp[i - 1][j + 1][0] : 0) + dp[i - 1][j][0];
            }
            dp[i][j][1] = (j > 0 ? dp[i - 1][j - 1][1] : 0) + (j < 9 ? dp[i - 1][j + 1][1] : 0) + dp[i - 1][j][1];
            if (j < s[i] - '0') dp[i][j][1] += (j > 0 ? dp[i - 1][j - 1][0] : 0) + (j < 9 ? dp[i - 1][j + 1][0] : 0) + dp[i - 1][j][0];
            if (j > 1) dp[i][j][1]++;
        }
    }
    int ans = 0;
    for (int j = 0; j < 10; j++) ans += dp[n - 1][j][1];
    ans--;
    return ans;
}

bool good(ll x) {
    vector<int> a;
    while (x > 0) {
        a.pb(x % 10);
        x /= 10;
    }
    for (int i = 0; i < (int)a.size() - 1; i++) {
        if (abs(a[i] - a[i + 1]) > 1) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k;
    cin >> k;
    k--;
    ll left = 0, right = 3234566667;
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        int cnt = check(to_string(mid));
        if (cnt > k || (cnt == k && good(mid))) right = mid;
        else left = mid;
    }
    cout << right;
    return 0;
}
