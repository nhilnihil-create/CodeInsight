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
    ll n;
    cin >> n;
    map<ll, int> mp;
    for (ll i = 2; i * i <= n; ++i) {
        while(1) {
            if (n % i != 0) break;
            n /= i;
            ++mp[i];
        }
    }
    if (n != 1) ++mp[n];
    int ans = 0;
    for (auto p: mp) {
        int tmp = p.second;
        int idx = 1;
        while(1) {
            if (tmp - idx < 0) break;
            tmp -= idx;
            ++idx;
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
