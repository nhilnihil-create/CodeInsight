#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define mod 998244353
#define INF 1 << 30
#define MAX 1 << 18

int solve(int src, int count, vector<vector<int>>& adj, vector<bool>& color, int* dp) {

    if(dp[src] != -1) {
        return dp[src];
    }

    int ans = MAX;

    bool flag = false;

    int tmp;

    for(auto node: adj[src]) {
        flag = true;
        if(color[node]) {
            tmp = solve(node, 0, adj, color, dp);
        } else {
            tmp = solve(node, 0, adj, color, dp);
        }

        if(color[node] || (color[node] == color[src])) {
            ans = min(ans, (count + tmp));
        } else {
            ans = min(ans, (count + tmp + 1));
        }
    }

    if(flag)
        return dp[src] = ans;

    return dp[src] = count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w;

    cin >> h >> w;

    int n = h*w;

    vector<vector<int>> adj(n);
    vector<bool> color(n);

    char ch;

    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            cin >> ch;

            int node = i*w + j;

            if(ch == '#') {
                color[node] = false;
            } else {
                color[node] = true;
            }

            if((node + 1) < n && (j+1) < w) {
                adj[node].push_back(node+1);
            }
            if((node + w) < n && (i+1) < h) {
                adj[node].push_back(node+w);
            }
        }
    }

    int dp[n];

    for(int i = 0; i < n; i++) {
        dp[i] = -1;
    }

    int ans;

    if(color[0]) {
        ans = solve(0, 0, adj, color, dp);
    } else {
        ans = solve(0, 1, adj, color, dp);
    }

    cout << ans << endl;

    return 0;
}