#include <iostream>
#include <queue>
using namespace std;

int n;
char c[101];
int g[101][101];
int t = 0;
int visit[101];
int finish[101];
int d[101];
int dist = 0;

void bfs(int start) {
    t++;
    queue<int> q;
    q.push(start);
    c[start] = 'g';
    visit[start] = t;
    while(!q.empty()) {
        t ++;
        int now = q.front();
        dist ++;
        for (int i = 1; i <= n ; ++i) {
            if(g[now][i] && c[i] == 'w') {
                q.push(i);
                c[i] = 'g';
                visit[i] = t;
                d[i] = d[now] + 1;
            }
        }
        q.pop();
        c[now] = 'b';
        finish[now] = t;
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n ; ++i) {
        int u, k;
        cin >> u >> k;
        for (int j = 0; j < k; ++j) {
            int v;
            cin >> v;
            g[u][v] = 1;
        }
    }

    for (int l = 0; l < n; ++l) {
        c[l+1] = 'w';
    }

    for (int i1 = 1; i1 <=n ; ++i1) {
        d[i1] = -1;
    }
    for (int m = 1; m <= n ; ++m) {
        d[1] = 0;
        if(c[m] == 'w') bfs(m);
        break;

    }
    for (int j1 = 1; j1 <=n ; ++j1) {
        cout << j1 << " " << d[j1] << endl;
    }

    return 0;
}

