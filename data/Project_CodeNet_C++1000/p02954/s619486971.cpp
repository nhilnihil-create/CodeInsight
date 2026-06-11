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
    int cnt = 0;
    vector<int> ans(n, 0);
    rep(i, n) {
        if (s[i] == 'R') ++cnt;
        else {
            ans[i] += cnt / 2;
            ans[i-1] += cnt - cnt / 2;
            cnt = 0;
        }
    }
    cnt = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'L') ++cnt;
        else {
            ans[i] += cnt / 2;
            ans[i+1] += cnt - cnt / 2;
            cnt = 0;
        }
    }
    rep(i, n) {
        if (i >= 1) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
