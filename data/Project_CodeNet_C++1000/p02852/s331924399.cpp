#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define sz(x) int(x.size())
const ll mod = 1000000007;
const int INF = 100100100;

int main() {
    int n,m; cin >> n >> m;
    string s; cin >> s;
    int dp[n+1]; rep(i,n+1) dp[i] = INF;
    dp[0] = 0;
    int check = 0;
    int last[n+1]; rep(i,n+1) last[i] = -1;
    rep(i,n) {
        if (s[i] == '1') continue;
        for (int j = max(check, i)+1; (j <= m+i && j <= n); j++) {
            check = max(check, j);
            if (s[j] == '1') continue;
            if (dp[j] > dp[i]+1) {
                dp[j] = dp[i]+1;
                last[j] = i;
            }
        }
    }
    if (dp[n] == INF) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> ans;
    int now = n;
    while (now != -1) {
        ans.push_back(now);
        now = last[now];
    }
    reverse(all(ans));
    rep(i,sz(ans)-1) {
        printf("%d ", ans[i+1] - ans[i]);
    }
    printf("\n");
    
    return 0;
}
