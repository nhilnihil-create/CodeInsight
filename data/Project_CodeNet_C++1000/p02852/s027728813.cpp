#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<int, int>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

const int INF = 1<<30;

int main() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    vector<int> dp(n+1, INF);
    dp[n] = 0;
    queue<int> que;
    que.push(0);
    for(int i = n-1; i >= 0; --i) {
        while(1) {
            if(que.empty()) {
                cout << -1 << endl;
                return 0;
            }
            if(que.front() != INF && (int)que.size() <= m) break;
            que.pop();
        }
        if(s.at(i) == '0') dp[i] = que.front() + 1;
        que.push(dp[i]);
    }

    vector<int> ans;
    int x = 0;
    int rest = dp[0];
    while(x < n) {
        --rest;
        int i = 1;
        while(dp[x+i] != rest) ++i;
        ans.push_back(i);
        x += i;
    }
    for(int i = 0; i < (int)ans.size(); ++i) {
        if(i == (int)ans.size() - 1) cout << ans.at(i) << endl;
        else cout << ans.at(i) << " ";
    }
}