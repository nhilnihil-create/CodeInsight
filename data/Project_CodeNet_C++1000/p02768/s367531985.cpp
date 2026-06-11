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

ll pow(ll a, ll b) {
    ll ret = 1;
    while(b > 0) {
        if (b&1) ret = (a * ret) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ret;
}

ll factorial(ll a, ll b) {
    ll ret = 1;
    for (ll i = 0; i < b; ++i) {
        ret = (ret * a) % mod;
        --a;
    }
    return ret;
}

ll inv(ll a) {
    return pow(a, mod-2);
}

ll combination(ll a, ll b) {
    return factorial(a, b) * inv(factorial(b, b)) % mod;
}

int main() {
    ll n, a, b;
    cin >> n >> a >> b;
    ll total = pow(2LL, n) - 1;
    ll a_num = combination(n, a);
    ll b_num = combination(n, b);
    ll ans = total;
    ans = (ans - a_num < 0) ? ans - a_num + mod : ans - a_num;
    ans = (ans - b_num < 0) ? ans - b_num + mod : ans - b_num;
    cout << ans << endl;
    return 0;
}
