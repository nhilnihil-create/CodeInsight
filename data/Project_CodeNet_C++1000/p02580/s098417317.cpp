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
    vector<int> h_accum(h);
    vector<int> w_accum(w);
    set<pair<int, int>> st;
    rep(i, m) {
        int hh, ww;
        cin >> hh >> ww;
        --hh, --ww;
        ++h_accum[hh];
        ++w_accum[ww];
        st.insert(make_pair(hh, ww));
    }
    int h_max = *max_element(h_accum.begin(), h_accum.end());
    int w_max = *max_element(w_accum.begin(), w_accum.end());
    vector<int> h_max_v, w_max_v;
    rep(i, h) if(h_accum[i] == h_max) h_max_v.push_back(i);
    rep(i, w) if(w_accum[i] == w_max) w_max_v.push_back(i);
    if ((ll)(h_max_v.size()) * (ll)(w_max_v.size()) > m) {
        cout << h_max + w_max << endl;
        return 0;
    }
    rep(i, (int)(h_max_v.size())) {
        rep(j, (int)(w_max_v.size())) {
            if (st.count(make_pair(h_max_v[i], w_max_v[j])) == 0) {
                cout << h_max + w_max << endl;
                return 0;
            }
        }
    }
    cout << h_max+ w_max - 1 << endl;
    return 0;
}
