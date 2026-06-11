#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1001001001;

int main() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<int> dp(n+1, INF);
    dp[n] = 0;
    queue<int> q;
    q.push(0);
    for (int i = n-1; i >= 0; i--) {
        while (1) {
            if (q.size() == 0) {
                cout << -1 << endl;
                return 0;
            }
            if (q.front() != INF && q.size() <= m) break;
            q.pop();
        }
        if (s[i] == '0') dp[i] = q.front()+1;
        q.push(dp[i]);
    } 
    vector<int> ans;
    int x;
    int rest = dp[0];
    while (x < n) {
        rest--;
        int i = 1;
        while (dp[x+i] != rest) i++;
        ans.push_back(i);
        x += i;
    }
    rep(i,ans.size()) {
        cout << ans[i] << endl;
    }
    return 0;
}