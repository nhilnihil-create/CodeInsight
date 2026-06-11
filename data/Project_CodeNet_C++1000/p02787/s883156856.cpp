#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, n;
    cin >> h >> n;

    vector<int> a(n), b(n);
    for(int i=0; i<n; i++){
        cin >> a[i] >> b[i];
    }

    vector<int> dp(h+1, numeric_limits<int>::max());
    dp[0] = 0;
    for(int k=0; k<=h; k++){
        for(int j=0; j<n; j++){
            int target = max(k - a[j], 0);
            dp[k] = min(dp[k], dp[target] + b[j]);
        }
    }

    cout << dp[h] << "\n";
    return 0;
}
