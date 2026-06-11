#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>
#include <random>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 10000000000;
const double PI = acos(-1);
const ll mod = 1000000007;

typedef pair<int, int> P;
vector<int> h_idx;
vector<int> w_idx;

int main()
{
    int H, W, M;
    cin >> H >> W >> M;
    set<P> s;
    vector<int> row(H);
    vector<int> col(W);
    rep(i, M) {
        int h, w;
        cin >> h >> w;
        h--;
        w--;
        row[h]++;
        col[w]++;
        s.insert(make_pair(h, w));
    }

    int max_row = 0;
    int max_col = 0;
    rep(i, H) max_row = max(max_row, row[i]);
    rep(i, W) max_col = max(max_col, col[i]);

    rep(i, H) {
        if (row[i] == max_row) h_idx.push_back(i);
    }
    rep(i, W) {
        if (col[i] == max_col) w_idx.push_back(i);
    }

    int ans = max_row + max_col;
    for (auto i : h_idx) {
        for (auto j : w_idx) {
            if (s.count(make_pair(i, j)) == 0) {
                cout << ans << endl;
                return 0;
            }
        }
    }

    ans--;
    cout << ans << endl;
    return 0;
}
