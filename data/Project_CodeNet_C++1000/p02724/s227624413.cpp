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
    ll x;
    cin >> x;
    ll ans = (x / 500LL) * 1000LL;
    x %= 500;
    ans += (x / 5LL) * 5LL;
    cout << ans << endl;
    return 0;
}