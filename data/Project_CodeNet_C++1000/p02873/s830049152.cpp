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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ans(n + 1, 0);
    rep(i, n) {
        if (s[i] == '<') {
            ans[i+1] = ans[i] + 1;
        }
    }
    // rep(i, n + 1) {
    //     cout << ans[i] << " ";
    // }
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '>') {
            ans[i] = max(ans[i], ans[i+1] + 1);
        }
    }
    // cout << "test2" << endl;
    ll sum =  0;
    rep(i, n + 1) {
        // cout << ans[i] << " ";
        sum += (ll)ans[i];
    }
    // cout << endl;
    cout << sum << endl;
    return 0;
}
