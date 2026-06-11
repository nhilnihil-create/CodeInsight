#include<bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define bg(x) (x).begin()
#define ed(x) (x).end()
#define ar array
#define ll long long int

const ll mod = 1e9 + 7;

int main() {
   
    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> dp(max(n + 1, 4), 0);
        dp[3] = 1;
        for (int i = 4; i <= n; ++i) {
        	dp[i] = 1;
        	for (int j = 3; j <= n; ++j) {
        		if (i - j >= 3) {
        			dp[i] = (dp[i] + dp[j]) % mod;
        		}
        	}
        }
        cout << dp[n];
    }

    return 0;
}