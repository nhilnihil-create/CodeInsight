#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int MAX=1000005;
int head[MAX],ver[MAX],next1[MAX],a[MAX];
int cnt=0;
int n,m;
void add(int u, int v) {
    ver[cnt] = v;
    next1[cnt] = head[u];
    head[u] = cnt++;
}
bool bfs(int x) {
    queue<int> q;
    q.push(x);
    a[x] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; ~i; i = next1[i]) {
            int v = ver[i];
            if (a[v] == -1) {
                a[v] = u;
                q.push(v);
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (a[i] == -1) {
            return false;
        }
    }
    return true;
}
int main(void) {
    cin >> n >> m;    
    cnt = 0;
    memset(head, -1, sizeof(head));
    memset(a, -1, sizeof(a));
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v);        
        add(v, u);        
    }

    if (!bfs(1)) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for (int i = 2; i <= n; i++) {
            cout << a[i] << endl;
        }
    }
    
    return 0;
}
