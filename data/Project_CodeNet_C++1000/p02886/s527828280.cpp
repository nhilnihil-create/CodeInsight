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

int main() {
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i, n) cin >> d[i];
    int ans = 0;
    rep(i, n) rep(j, n) {
        if (i == j) continue;
        ans += d[i] * d[j];
    }
    cout << ans / 2 << endl;
    return 0;
}