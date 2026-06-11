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
    int ans = 0;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    int cnt = 0;
    rep(i, n-1) {
        //cout << h[i+1] << " " << h[i] << endl;
        if (h[i+1] > h[i]) {
            ans = max(ans, cnt);
            cnt = 0;
        }
        else {
            ++cnt;
        }
        if (i == n - 2) {
            ans = max(ans, cnt);
        }
    } 
    cout << ans << endl;
    return 0;
}