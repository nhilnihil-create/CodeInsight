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

#define P (1'000'000'007)

signed main() {
    capi(n);

    vector<vector<pair<int, int>>> vc(n, vector<pair<int, int>>());
    rep(i, n) {
        capi(a);

        rep(j, a) {
            int x, y;
            cin >> x >> y; --x;

            vc[i].push_back(make_pair(x, y));
        }
    }

    int ans = 0;
    rep(i, 1 << n) {
        int res = 0;
        rep(j, n) {
            if ((i >> j) & 1) {
                for (auto p: vc[j]) {
                    if (((i >> p.first) & 1) == p.second) ;
                    else {
                        goto END;
                    }
                }
                ++res;
            }
        }
        chmax(ans, res);
END:
    ;
    }

    cout << ans;

    return 0;
}
