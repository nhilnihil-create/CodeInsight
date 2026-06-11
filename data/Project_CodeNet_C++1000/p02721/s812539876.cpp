#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int, int>
#define pb push_back
int n, k, c;
string s;
int const N = 2e5 + 10;
int dp[N];
int solve(int i){ 
    if(i >= n){
        return 0;
    }
    if(dp[i] != -1) return dp[i];
    if(s[i] == 'x') return dp[i] = solve(i + 1);
    return dp[i] = max(solve(i + 1), 1 + solve(i + c));
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k >> c; c++;
    cin >> s;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n; i++) {
        solve(i);
    }
    vector<int> ans;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'x') continue;
        if(dp[i] == dp[i + 1]) {
            i += c - 1;
            continue;
        }
        if(dp[i] != dp[i + 1]) {
            ans.pb(i + 1);
            i += c - 1;
        }
    }
    if(dp[0] > k) ans.clear();
    for(auto x: ans) cout << x << endl;

    return 0;
}

