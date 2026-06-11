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
    vector<ll> num;
    num.push_back(1);
    num.push_back(n);
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            num.push_back(i);
        }
    }
    ll ans = 1e18;
    for (auto nn: num) {
        ans = min(ans, nn - 1 + (n / nn) - 1);
    }
    cout << ans << endl;
    return 0;
}
