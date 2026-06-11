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
    ll a;
    string b;
    cin >> a >> b;
    int n = b.size();
    ll bb = 0;
    rep(i, n) {
        if (b[i] != '.') {
            bb = bb * 10 + (b[i] - '0');
        }
    }
    ll ans = a * bb;
    cout << ans / 100 << endl;
    return 0;
}
