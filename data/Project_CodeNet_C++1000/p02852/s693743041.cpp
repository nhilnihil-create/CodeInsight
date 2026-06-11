#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i ++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> PL;
typedef pair<int,int> P;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

int main() {
    int n,m; cin >> n >> m;
    string s; cin >> s;

    vector<int> dp(n + 1,INF);
    dp[n] = 0;
    queue<int> q;
    q.push(0);
    for (int i = n - 1;i >= 0; i --) {
        while (1) {
            if (q.size() == 0) {
                puts("-1");
                return 0;
            }
            if (q.front() != INF && q.size() <= m) break;
            q.pop();
        }
        if (s[i] == '0') dp[i] = q.front() + 1;
        q.push(dp[i]);
    }

    vector<int> ans;
    int x = 0;
    int res = dp[0];
    while (x < n) {
        res --;
        int i = 1;
        while (dp[x + i] != res) i ++;
        ans.push_back(i);
        x += i;
    }
    rep(i,ans.size()) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}