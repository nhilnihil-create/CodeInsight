#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int h, w, m;
    cin >> h >> w >> m;
    //vector<vector<bool>> hw(h, vector<bool>(w, false));
    set<pair<int, int>> st;
    vector<int> hnum(h, 0);
    vector<int> wnum(w, 0);
    rep(i, m) {
        int hh, ww;
        cin >> hh >> ww;
        --hh, --ww;
        st.insert(make_pair(hh, ww));
        ++hnum[hh];
        ++wnum[ww];
    }
    int hnum_max = *max_element(hnum.begin(), hnum.end());
    int wnum_max = *max_element(wnum.begin(), wnum.end());
    vector<int> hmax_idx;
    vector<int> wmax_idx;
    rep(i, h) {
        if (hnum[i] == hnum_max) hmax_idx.push_back(i);
    }
    rep(i, w) {
        if (wnum[i] == wnum_max) wmax_idx.push_back(i);
    }
    if ((ll)(hmax_idx.size()) * (ll)(wmax_idx.size()) > m) {
        cout << hnum_max + wnum_max << endl;
        return 0;
    }
    int ans = 0;
    for (auto hidx: hmax_idx) {
        for  (auto widx: wmax_idx) {
            if (st.count(make_pair(hidx, widx)) != 0) {
                ans = max(ans, hnum_max + wnum_max - 1);
            }
            else {
                ans = max(ans, hnum_max + wnum_max);
            }
        }
    }
    cout << ans << endl;
    return 0;
}