#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);

    int h, w;
    cin >> h >> w;
    int n;
    cin >> n;
    vector<pair<int,int>> P;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        P.emplace_back(x, y);
    }

    vector<int> H(h, 0);
    vector<int> W(w, 0);

    for (auto& p : P) {
        int x = p.first;
        int y = p.second;
        ++H[x];
        ++W[y];
    }

    int res = 0;
    for (int i = 0; i < h; ++i) {
        res = max(res, H[i]);
    }
    for (int i = 0; i < w; ++i) {
        res = max(res, W[i]);
    }

    int mxh = *max_element(H.begin(), H.end());
    int mxw = *max_element(W.begin(), W.end());

    vector<bool> HH(h, false);
    vector<bool> WW(w, false);

    int ch = 0;
    int cw = 0;
    for (int i = 0; i < h; ++i) {
        if (H[i] == mxh) {
            HH[i] = true;
            ++ch;
        }
    }
    for (int i = 0; i < w; ++i) {
        if (W[i] == mxw) {
            WW[i] = true;
            ++cw;
        }
    }

    int cnt = 0;
    for (auto& p : P) {
        int x = p.first, y = p.second;
        if (HH[x] && WW[y]) {
            ++cnt;
        }
    }

    int ans = mxh + mxw;
    if (ch * 1LL * cw <= cnt) {
        --ans;
    }

    res = max(res, ans);

    cout << res << '\n';

    return 0;
}