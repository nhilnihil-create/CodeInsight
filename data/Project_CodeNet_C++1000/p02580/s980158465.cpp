#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii; 
const int N = 2e5+10, mod = 1e9+7;

void solve() {
    int h, w, m; cin >> h >> w >> m;

    int hc[h + 1], wc[w + 1];
    pii pos[m + 1];
    memset(pos, 0, sizeof(pos));
    memset(hc, 0, sizeof(hc));
    memset(wc, 0, sizeof(wc));

    for (int i = 1; i <= m; ++i) {
        int x, y; cin >> x >> y;
        pos[i] = {x, y};
        ++hc[x];
        ++wc[y];
    }

    int hmx = 0, hcnt = 0;
    for (int i = 1; i <= h; ++i) {
        if (hc[i] == hmx) {
            ++hcnt;
        }
        if (hc[i] > hmx) {
            hcnt = 1;
            hmx = hc[i];
        }
    }

    int wmx = 0, wcnt = 0;
    for (int i = 1; i <= w; ++i) {
        if (wc[i] == wmx) {
            ++wcnt;
        }
        if (wc[i] > wmx) {
            wcnt = 1;
            wmx = wc[i];
        }
    }

    int ans = hmx + wmx, cnt = 0;
    for (int i = 1; i <= m; ++i) {
        int x = pos[i].first, y = pos[i].second;
        if (hc[x] == hmx && wc[y] == wmx) {
            ++cnt;
        }
    }
    
    if (hcnt * wcnt == cnt) {
        --ans;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    while (t--) solve();
    return 0;
}
