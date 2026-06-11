#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

const int N = 20;
vector <pair <int, int> > v[N];
bool is[N], vis[N], ans;

void dfs(int x) {
    vis[x] = true;
    if (!is[x]) return;
    for (auto y : v[x]) {
        if (y.se != is[y.fi]) ans = false;
        if (!vis[y.fi]) {
            dfs(y.fi);
        }
    }
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        while (a--) {
            int x, y;
            scanf("%d %d", &x, &y);
            v[i].pb({x - 1, y});
        }
    }
    int res = 0;
    for (int i = 0; i < (1 << n); i++) {
        int hold = 0;
        for (int j = 0; j < n; j++) {
            if ((1 << j) & i) {
                is[j] = true;
                hold++;
            } else {
                is[j] = false;
            }
            vis[j] = false;
        }
        ans = true;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i);
            }
        }
        if (ans) {
            res = max(res, hold);
            //printf("%d\n", i);
        }
    }
    printf("%d", res);
    return 0;
}
