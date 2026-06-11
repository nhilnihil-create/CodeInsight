#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define ld long double

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(NULL),cout.tie(NULL);
    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> v(n);
    for(int i=0;i<n;i++) {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }
    sort(v.begin(), v.end());
    vector<int> dp(t + 1, 0);
    for(int i=0;i<n;i++) {
        for(int j=t-1;j>=0;j--) {
            dp[min(t, j + v[i].first)] = max(dp[min(t, j + v[i].first)], dp[j] + v[i].second);
        }
    }
    cout << dp[t] << endl;
}
