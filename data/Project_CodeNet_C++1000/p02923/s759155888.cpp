
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5;
int n, res;
int dp[N], a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0 && a[i] <= a[i - 1]) {
            dp[i] = dp[i - 1] + 1;
            res = max(res, dp[i]);
        }
    }
    cout << res << endl;

    return 0;
}

