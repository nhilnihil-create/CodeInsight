#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int n, m; cin >> n >> m;
    vector<pair<int, int>> res;
    if (n % 2 == 1) {
        //奇数
        for (int l = 1, r = n - 1; l < r; ++l, --r) {
            res.push_back(make_pair(l, r));
        }
    } else {
        //偶数
        bool over = false;
        for (int l = 1, r = n - 1; l < r; ++l, --r) {
            if (!over && r - l <= n / 2) {
                ++l;
                over = true;
            }

            res.push_back(make_pair(l, r));
        }
    }

    for (int i = 0; i < m; ++i) {
        cout << res[i].first << ' ' << res[i].second << endl;
    }
}