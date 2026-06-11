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
    vector<int> l(n);
    rep(i, n) cin >> l[i];
    sort(l.begin(), l.end());
    int ans = 0;
    rep(i, n) {
        for (int j = i + 1; j < n; ++j) {
            int idx = lower_bound(l.begin(), l.end(), l[i] + l[j]) - l.begin() - 1;
            ans += max(0, idx - j);
        }
    }
    cout << ans << endl;
    return 0;
}
