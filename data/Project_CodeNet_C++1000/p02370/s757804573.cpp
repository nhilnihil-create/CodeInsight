#include <bits/stdc++.h>
using namespace std;
struct Fast {
    Fast() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    }
} fast;

void yes() {
    cout << "Yes" << endl;
    exit(0);
}
void no() {
    cout << "No" << endl;
    exit(0);
}
#define REP(i, n) for (long long i = 0; i < (n); i++)

vector<bool> visited(105);
vector<vector<int>> edge(105);
bool dfs(int cur, int par) {
    // if a cycle doesn't exist, return true
    visited[cur] = true;
    bool ic = false;
    if (edge[cur].size() == 0) {
        return true;
    } else {
        for (int i = 0; i < edge[cur].size(); i++) {
            if (edge[cur][i] == par) {
                continue;
            }
            if (visited[edge[cur][i]]) {
                ic = true;
                break;
            } else {
                visited[edge[cur][i]] = true;
            }
            if (!dfs(edge[cur][i], cur)) {
                ic = true;
            }
        }
        if (ic) {
            return false;
        } else {
            return true;
        }
    }
}
int ctoi(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    return 0;
}
long long modpow(long long m, long long n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        long long t = modpow(m, n / 2);
        return t * t % 2019;
    } else {
        return modpow(m, n - 1) * m % 2019;
    }
}
signed main() {
    long long v, e;
    cin >> v >> e;
    vector<int> ans;
    queue<int> zeros;
    vector<vector<int>> graph(v);
    vector<int> degree(v);
    REP(i, e) {
        // https/chess.com
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        degree[b]++;
    }
    REP(i, v) {
        if (degree[i] == 0) {
            zeros.push(i);
        }
    }
    while (zeros.size() > 0) {
        int cur = zeros.front();
        zeros.pop();
        ans.push_back(cur);
        for (int i = 0; i < graph[cur].size(); i++) {
            degree[graph[cur][i]]--;
            if (degree[graph[cur][i]] == 0) {
                zeros.push(graph[cur][i]);
            }
        }
    }
    REP(i, ans.size()) { cout << ans[i] << endl; }
}
