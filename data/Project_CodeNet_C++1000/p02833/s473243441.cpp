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
const ll LINF = 1001002003004005006ll;

int main() {
    ll n;
    cin >> n;
    if (n % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    ll idx = 10;
    while(1) {
        if (idx > n) break;
        ans += n / idx;
        idx *= 5LL;
    }
    cout << ans << endl;
    return 0;
}
