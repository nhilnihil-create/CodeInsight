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
    rep(a, n) {
        for (int b = a + 1; b < n; ++b) {
            for (int c = b + 1; c < n; ++c) {
                if (l[b] - l[a] < l[c] && l[c] < l[a] + l[b]) ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
