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
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n, m;
    cin >> n >> m;
    vector<bool> ac_flg(n, false);
    vector<int> wa_cnt(n, 0);
    rep(i, m) {
        int p;
        string s;
        cin >> p >> s;
        --p;
        if (s == "AC") {
            ac_flg[p] = true;
        }
        else if (!ac_flg[p]) {
            ++wa_cnt[p]; 
        }
    }
    int ac_cnt = 0;
    int ans_wa_cnt = 0;
    rep(i, n) {
        //cout << i << " " << ac_flg[i] << endl;
        if (ac_flg[i]) {
            ++ac_cnt;
            ans_wa_cnt += wa_cnt[i];
        }
    }
    cout << ac_cnt << " " << ans_wa_cnt << endl;
    return 0;
}
