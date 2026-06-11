#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define fi first
#define se second
#define pb push_back

const int N = 100005;
vector <pair <int, int> > v[N];
int res[N];
bool vis[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        v[x].pb({y, i});
        v[y].pb({x, i});
    }
    queue <pair <int, int> > q;
    q.push({1, 0});
    vis[1] = true;
    int k = 0;
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        int cnt = 1;
        for (auto y : v[x.fi]) {
            if (!vis[y.fi]) {
                if (cnt == x.se) cnt++;
                res[y.se] = cnt;
                k = max(k, cnt);
                q.push({y.fi, cnt});
                vis[y.fi] = true;
                cnt++;
            }
        }
    }
    printf("%d\n", k);
    for (int i = 1; i < n; i++) {
        printf("%d\n", res[i]);
    }
    return 0;
}
