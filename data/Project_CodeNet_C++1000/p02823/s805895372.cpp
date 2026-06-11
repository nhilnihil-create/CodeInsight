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
    ll n, a, b;
    cin >> n >> a >> b;
    if ((b - a) % 2 == 0) {
        cout << (b - a) / 2LL << endl;
    }
    else {
        ll tmp = min(a - 1LL, n - b);
        cout << tmp + 1 + (b - a - 1) / 2LL << endl;
    }
    return 0;
}
