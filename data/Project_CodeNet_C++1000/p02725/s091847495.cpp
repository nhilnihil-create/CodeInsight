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
    int k, n;
    cin >> k >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 1e8;
    rep(i, n) {
        if (i == n - 1) {
            ans = min(ans, k-(a[0]+k - a[i]));
        }
        else {
            ans = min(ans, k-(a[i+1] - a[i]));
        }
    }
    cout << ans << endl;
    return 0;
}
