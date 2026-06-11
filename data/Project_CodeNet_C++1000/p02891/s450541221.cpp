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
    string s;
    ll k;
    cin >> s >> k;
    bool all_same_flg = true;
    ll n = s.size();
    rep(i, n-1) {
        if (s[i] != s[i+1]) all_same_flg = false;
    }
    if (all_same_flg) {
        cout << s.size() * k / 2 << endl;
        return 0;
    }
    string ss = s + s;
    ll m = ss.size();
    ll cnt = 1;
    ll change_cnt = 0;
    rep(i, n) {
        if (s[i] == s[i+1]) {
            ++cnt;
        }
        else {
            change_cnt += cnt / 2LL;
            cnt = 1;
        }
    }
    cnt = 1;
    ll change_cnt2 = 0;
    rep(i, m) {
        if (ss[i] == ss[i+1]) {
            ++cnt;
        }
        else {
            change_cnt2 += cnt / 2LL;
            cnt = 1;
        }
    }
    //cout << change_cnt << " " << change_cnt2 << endl;
    cout << change_cnt + (change_cnt2 - change_cnt) * (k - 1LL) << endl;
    return 0;
}
