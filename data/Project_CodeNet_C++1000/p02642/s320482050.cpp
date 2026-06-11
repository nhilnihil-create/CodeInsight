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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> cnt(1e6+1, 0);
    rep(i, n) {
        int x = a[i];
        if (cnt[x] != 0) {
            cnt[x] = 2;
            continue;
        }
        int idx = x;
        while(1) {
            if (idx > 1e6) break;
            ++cnt[idx];
            idx += x;
        }
    }
    // rep(i, 26) {
    //     cout << cnt[i] << " ";
    // }
    // cout << endl;
    int ans = 0;
    rep(i, n) {
        if (cnt[a[i]] == 1) ++ans;
    }
    cout << ans << endl;
    return 0;
}
