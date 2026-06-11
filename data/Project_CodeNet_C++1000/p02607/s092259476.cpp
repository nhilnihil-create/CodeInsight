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

int a[105];

int main() {
    int n;
    cin >> n;
    rep(i, n) cin >> a[i];
    int ans = 0;
    rep(i, n) {
        if (((i+1)&1) && (a[i]&1)) ++ans;
    }
    cout << ans << endl;
    return 0;
}
