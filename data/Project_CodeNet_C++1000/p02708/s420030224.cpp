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
    ll n, k;
    cin >> n >> k;
    ll sum = 0;
    for (ll i = k; i <= n + 1; ++i) {
        ll min = (0LL + i-1LL) * i / 2LL;
        ll max = (n-i+1LL + n) * i / 2LL;
        //cout << i << " " << min << " " << max << endl;
        sum = (sum + max - min + 1LL) % mod;
    }
    cout << sum << endl;
    return 0;
}
