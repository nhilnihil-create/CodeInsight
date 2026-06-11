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

ll solve (string s) {
    ll cnt = 0, ret = 0;
    rep(i, (int)s.size()) {
        ++cnt;
        if (i == (int)s.size() - 1 || s[i] != s[i+1]) {
            ret += cnt / 2;
            cnt = 0;
        }
    }
    return ret;
}

int main() {
    string t;
    cin >> t;
    ll k;
    cin >> k;

    bool flag = true;
    ll n = t.size();
    rep(i, n-1) {
        if (t[i] != t[i+1]) {
            flag = false;
        }
    }
    if (flag) {
        cout << n * k / 2LL << endl;;
    }
    else {
        string v1 = t;
        string v2 = t + t;
        ll r1 = solve(v1);
        ll r2 = solve(v2);
        cout << r1 + (r2 - r1) * (k - 1LL) << endl;
    }
    return 0;
}
