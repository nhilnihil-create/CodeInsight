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
#include <cassert>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

ll factorial(ll a, ll b) {
    ll ret = 1;
    while(1) {
        if (b == 0) break;
        ret = ret * a % mod;
        --a;
        --b;
    }
    return ret;
}

ll expo(ll a, ll b) {
    ll ret = 1;
    while(1) {
        if (b == 0) break;
        if (b&1LL) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1LL;
    }
    return ret;
}

ll inv(ll a) {
    return expo(a, mod-2);
}

ll comb(ll a, ll b) {
    //cout << factorial(a, b) << " " << factorial(b, b) << " " << inv(factorial(b,b)) << endl;
    return factorial(a, b) * inv(factorial(b,b)) % mod;
}

int main() {
    ll n, k;
    cin >> n >> k;
    for (ll i = 1; i <= k; ++i) {
        cout << comb(n-k+1, i) * comb(k-1, i-1) % mod << endl;
    }
    return 0;
}