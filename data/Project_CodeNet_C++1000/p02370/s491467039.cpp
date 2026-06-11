#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (int)b; i++)
#define all(v) v.begin(), v.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    int in[n] = {};
    rep(i, 0, m) {
        int s, t;
        cin >> s >> t;
        g[s].push_back(t);
        in[t]++;
    }

    vector<int> ans;
    queue<int> que;
    rep(i, 0, n) {
        if (in[i] == 0) {
            que.push(i);
            ans.push_back(i);
        }
    }
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        for (auto next : g[now]) {
            in[next]--;
            if (in[next] == 0) {
                que.push(next);
                ans.push_back(next);
            }
        }
    }

    for (auto i : ans) cout << i << endl;
    return 0;
}

