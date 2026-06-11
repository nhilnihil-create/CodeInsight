#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int cnth[300010], cntw[300010];
int a[300010], b[300010];
pii p[300010];

bool cmp(int &x, int &y) {
    return cnth[x]>cnth[y];
}

bool cmp2(int &x, int &y) {
    return cntw[x]>cntw[y];
}

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, t; cin >> n >> m >> t;
    for (int i=0;i<t;i++) {
        cin >> p[i].fi >> p[i].se;
        cnth[p[i].fi]++; cntw[p[i].se]++;
    }
    sort(p, p+t);

    for (int i=1;i<=n;i++) a[i] = i;
    for (int i=1;i<=m;i++) b[i] = i;
    sort(a+1, a+n+1, cmp);
    sort(b+1, b+m+1, cmp2);

    int s = 1, w = 1;
    while (s<=n&&cnth[a[s]]==cnth[a[1]]) s++;
    while (w<=m&&cntw[b[w]]==cntw[b[1]]) w++;

    int ans = 0;
    for (int i=1;i<s;i++) for (int j=1;j<w;j++) {
        int g = binary_search(p, p+t, make_pair(a[i], b[j]));
        ans = max(ans, cnth[a[i]]+cntw[b[j]]-g);
        if (!g) break;
    }
    cout << ans << endl;
}
