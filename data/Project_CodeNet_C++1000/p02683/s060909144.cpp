#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <vector>
using namespace std;
const int maxn = 1e5+5;
typedef long long ll;
int a[20][20], c[20], vis[20];
int n, m, x;
int d[20];

void dfs(int u, int &ans) {
    if (u==n+1) {
        memset(d, 0, sizeof(d));
        int sum = 0;
        for (int i=1; i<=n; i++) {
            if (vis[i]==1) {
                sum+=c[i];
                for (int j=1; j<=m; j++) {
                    d[j]+=a[i][j];
                }
            }
        }

        for (int j=1; j<=m; j++) {
            if (d[j] < x) {
                return;
            }
        }
        if (ans == -1) {
            ans = sum;
        } else {
            ans = min(ans, sum);
        }
        return;
    }

    vis[u]=0;
    dfs(u+1, ans);
    vis[u]=1;
    dfs(u+1, ans);
}

int main() {
    cin >> n >> m >> x;
    for (int i=1; i<=n; i++) {
        cin >> c[i];
        for (int j=1; j<=m; j++) {
            cin >> a[i][j];
        }
    }   

    int ans = -1;
    dfs(1, ans);
    cout << ans << endl;
    return 0;
}