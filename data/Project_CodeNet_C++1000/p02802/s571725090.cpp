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
    vector<bool> flg(n, false);
    vector<int> cnt(n, 0);
    rep(i, m) {
        int p;
        string s;
        cin >> p >> s;
        --p;
        if (s == "AC") {
            flg[p] = true;
        }
        else if (!flg[p] && s == "WA") {
            ++cnt[p];
        }
    }
    int ac_ans = 0;
    int wa_ans = 0;
    rep(i, n) {
        if (flg[i]) {
            ++ac_ans;
            wa_ans += cnt[i];
        }
    }
    cout << ac_ans << " " << wa_ans << endl;
    return 0;
}
