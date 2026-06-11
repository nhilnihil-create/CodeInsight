/**
 *    author:  FromDihPout
 *    created: 2020-08-12
**/

#include <bits/stdc++.h>
using namespace std;

int n, x, y;
vector<int> paths;

void bfs(int start) {
    int dist = 0;
    queue<int> q;
    vector<bool> seen(n+1);
    q.push(start);
    seen[start] = true;
    
    while (!q.empty()) {
        int len = q.size();
        paths[dist] += len;
        while (len--) {
            int u = q.front();
            q.pop();
            if (!seen[u+1] && u+1 <= n) {
                q.push(u+1);
                seen[u+1] = true;
            }
            if (!seen[u-1] && u-1 >= 1) {
                q.push(u-1);
                seen[u-1] = true;
            }
            if (u == x && !seen[y]) {
                q.push(y);
                seen[y] = true;
            }
            if (u == y && !seen[x]) {
                q.push(x);
                seen[x] = true;
            }
        }
        dist++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> x >> y;
    paths.resize(n);
    for (int i = 1; i <= n; i++) {
        bfs(i);
    }
    
    for (int d = 1; d <= n - 1; d++) {
        cout << paths[d] / 2 << '\n';
    }
    return 0;
}