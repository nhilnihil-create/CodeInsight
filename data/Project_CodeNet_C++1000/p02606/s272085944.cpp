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
    int l, r, d;
    cin >> l >> r >> d;
    int ans = 0;
    for (int i = l; i <= r; ++i) {
        if (i % d == 0) {
            ++ans;
        }
    }
    cout << ans << endl;
    return 0;
}
