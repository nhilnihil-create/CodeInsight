#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 3e3 + 5;
int n, t, a, b, res;
int dp[N * 2];
ii A[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp, 255, sizeof dp);

    cin >> n >> t;
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        A[i].first = a;
        A[i].second = b;
    }
    sort(A, A + n);
    for (int i = 0; i < n; ++i) {
        a = A[i].first;
        b = A[i].second;
        for (int tt = N * 2 - 1; tt - a >= 0; --tt) {
            if (dp[tt - a] != -1 && tt - a < t) {
                dp[tt] = max(dp[tt], dp[tt - a] + b);
            }
        }
    }
    for (int i = 0; i < N * 2; ++i) {
        res = max(res, dp[i]);
    }
    cout << res << endl;

    return 0;
}

