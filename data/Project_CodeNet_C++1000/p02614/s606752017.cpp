#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define int long long int
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()
#define capi(x) int x;cin>>x
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using vi = vector<int>;

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}

signed main() {
    int h, w, k;
    cin >> h >> w >> k;

    vector<string> vs;

    rep(i, h) {
        string s;
        cin >> s;

        vs.push_back(s);
    }

    int ans = 0;

    rep(xh, 1 << h) {
        rep(xw, 1 << w) {
            int res = 0;
            rep(i, h) {
                rep(j, w) {
                    if ((xh >> i & 1) == 0 && (xw >> j & 1) == 0 && vs[i][j] == '#') {
                        res += 1;
                    }
                }
            }

            if (res == k) ++ans;
        }
    }

    cout << ans;

    return 0;
}