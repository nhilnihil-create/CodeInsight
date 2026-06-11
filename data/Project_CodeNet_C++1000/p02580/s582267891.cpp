#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;

int main() {
    int H, W, m;
    cin >> H >> W >> m;
    map<int, int> tate, yoko;
    set<pair<int, int>> st;
    rep(i, m) {
        int h, w;
        cin >> h >> w;
        yoko[w]++;
        tate[h]++;
        st.insert({h, w});
    }

    int mah = 0, maw = 0;
    for (auto p : tate)
        mah = max(mah, p.second);

    for (auto p : yoko)
        maw = max(maw, p.second);

    set<int> sth;
    for (auto p : tate) {
        if (mah == p.second)
            sth.insert(p.first);
    }

    set<int> stw;
    for (auto p : yoko) {
        if (maw == p.second)
            stw.insert(p.first);
    }

    int ans = mah + maw - 1;
    for (auto h : sth) {
        for (auto w : stw) {
            if (st.find({h, w}) == st.end()) {
                ans = mah + maw;
                cout << ans << endl;
                return 0;
            }
        }
    }

    cout << ans << endl;

    return 0;
}