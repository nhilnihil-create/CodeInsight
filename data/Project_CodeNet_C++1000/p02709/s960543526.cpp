#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

template<class T>
void chmax(T &x, T y) { if (x < y) x = y; }

const int N = 2010;
ll dp[N][N];

int main() {
    int n;
    cin >> n;
    vector<pair<ll, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.rbegin(), a.rend());
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n - i; j++) {
            if (!i && !j) continue;
            if (i) chmax(dp[i][j], dp[i - 1][j] + a[i + j - 1].first * (a[i + j - 1].second - i + 1));
            if (j) chmax(dp[i][j], dp[i][j - 1] + a[i + j - 1].first * (n - j - a[i + j - 1].second));
            if (i + j == n) chmax(ans, dp[i][j]);
        }
    }
    cout << ans << "\n";
}
