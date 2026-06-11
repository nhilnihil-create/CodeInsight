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

int gcd(int a, int b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int gcd_all;
    rep(i, n) {
        cin >> a[i];
        if (i == 0) {
            gcd_all = a[i];
        }
        else {
            gcd_all = gcd(gcd_all, a[i]);
        }
    }
    vector<int> v(1e6+1, 0);
    v[1] = 1;
    for (int i = 2; i <= 1e6; ++i) {
        if (v[i] == 0) {
            int idx = i;
            while(idx <= 1e6) {
                v[idx] = i;
                idx += i;
            }
        }
    }
    set<int> st;
    bool ok = true;
    rep(i, n) {
        int tmp = a[i];
        set<int> tmp_st;
        while(1) {
            if (tmp == 1) break;
            tmp_st.insert(v[tmp]);
            tmp /= v[tmp];
        }
        for (auto tt: tmp_st) {
            if (st.count(tt)) {
                ok = false;
                break;
            }
            st.insert(tt);
        }
        if (!ok) {
            //for (auto ss: st) {
            //    cout << ss << " ";
            //}
            //cout << endl;
            if (gcd_all == 1) {
                cout << "setwise coprime" << endl;
                return 0;
            }
            else {
                cout << "not coprime" << endl;
                return 0;
            }
        }
    }
    cout << "pairwise coprime" << endl;
    return 0;
}
