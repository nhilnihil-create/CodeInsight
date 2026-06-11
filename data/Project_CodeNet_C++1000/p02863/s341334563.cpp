#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, t;
    cin >> n >> t;
    pair<int, int> a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    vector<int> dp(t + 3002);
    sort(a, a + n);
    for(int i = 0; i < n; i++){
        for(int j = t - 1; j >= 0; j--)
            dp[j + a[i].first] = max(dp[j + a[i].first], dp[j] + a[i].second);
    }
    int ans = 0;
    for(int i = 0; i < dp.size(); i++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}