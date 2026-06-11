#include <bits/stdc++.h>
using namespace std;

void chmax (int &x, int a) {
    x = max(x, a);
}

int h, w;
char s[2004][2004];
set < int > ver_bor[2004], hor_bor[2004];  // vertical borders, horizontal borders

signed main () {
    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> s[i][j];
            if (s[i][j] == '#')
                hor_bor[i].insert(j);
        }
    }
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            if (s[j][i] == '#')
                ver_bor[i].insert(j);
        }
    }
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (s[i][j] == '.') {
                auto hor_it = hor_bor[i].lower_bound(j);
                auto ver_it = ver_bor[j].lower_bound(i);
                int l_hor = -1, r_hor = w, l_ver = -1, r_ver = h;
                if (hor_it != hor_bor[i].begin())
                    l_hor = *prev(hor_it);
                if (hor_it != hor_bor[i].end())
                    r_hor = *hor_it;
                if (ver_it != ver_bor[j].begin())
                    l_ver = *prev(ver_it);
                if (ver_it != ver_bor[j].end())
                    r_ver = *ver_it;
                chmax(ans, (r_hor - l_hor - 1) + (r_ver - l_ver - 1) - 1);
            }
        }
    }
    cout << ans << '\n';
}
