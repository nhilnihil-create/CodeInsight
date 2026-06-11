#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

struct cell {
    ll point = 0;
    ll num = 0;
};
bool v_cmp(const struct cell &p, const struct cell &q) { return p.num > q.num; }
// sort(v.begin(), v.end(), v_cmp); // small to large

int main() {
    ll H, W, M;
    cin >> H >> W >> M;

    map<ll, ll> field;
    vector<ll> f_h(H, 0);
    vector<ll> f_w(W, 0);
    for (int i = 0; i < M; i++) {
        ll h, w;
        cin >> h >> w;
        field[W * (h - 1) + w - 1] = 1;
        f_h[h - 1]++;
        f_w[w - 1]++;
    }

    vector<cell> h_cell(H);
    for (int i = 0; i < H; i++) {
        struct cell tmp;
        tmp.point = (ll)i + 1;
        tmp.num = f_h[i];
        h_cell[i] = tmp;
    }
    sort(h_cell.begin(), h_cell.end(), v_cmp);

    vector<cell> w_cell(W);
    for (int i = 0; i < W; i++) {
        struct cell tmp;
        tmp.point = (ll)i + 1;
        tmp.num = f_w[i];
        w_cell[i] = tmp;
    }
    sort(w_cell.begin(), w_cell.end(), v_cmp);

    // for (int i = 0; i < H; i++) {
    // cout << i << " " << h_cell[i].num << " " << h_cell[i].point << endl;
    // }

    // int h = 0;
    // int w = 0;
    ll max = 0;

    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            if (h_cell[h].num + w_cell[w].num < h_cell[0].num + w_cell[0].num) {
                break;
            }
            ll exp;
            if (field[W * (h_cell[h].point - 1) + w_cell[w].point - 1] != 1) {
                exp = h_cell[h].num + w_cell[w].num;
                if (exp > max) {
                    max = exp;
                }
                break;
            } else {
                exp = h_cell[h].num + w_cell[w].num - 1;
            }
            if (exp > max) {
                max = exp;
            }
        }
        if (h_cell[h].num + 1 < h_cell[0].num) break;
    }

    // while (h_cell[h].num + w_cell[w].num + 1 >= h_cell[0].num +
    // w_cell[0].num) { ll exp; if (field[W * (h_cell[h].point - 1) +
    // w_cell[w].point - 1] != 1) { exp = h_cell[h].num + w_cell[w].num;
    // } else {
    // exp = h_cell[h].num + w_cell[w].num - 1;
    // }
    // if (exp > max) {
    // max = exp;
    // }
    // if (h > w) {
    // w++;
    // } else {
    // h++;
    // }
    // if (h >= H) {
    // h--;
    // w++;
    // }
    // if (w >= W) {
    // w--;
    // h++;
    // }
    // if (h >= H || w >= W || M == H * W) {
    // break;
    // }
    // }

    cout << max << endl;

    return 0;
}
