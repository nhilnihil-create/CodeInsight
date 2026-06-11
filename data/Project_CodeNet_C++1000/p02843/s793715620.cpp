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
    ll x;
    cin >> x;
    int rest = x % 100;
    int num = 0;
    for (int i = 5; i >= 1; --i) {
        num += rest / i;
        rest = rest % i;
        // cout << rest << " " << num << endl;
    }
    // cout << num << endl;
    if (x / 100 >= num) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}
