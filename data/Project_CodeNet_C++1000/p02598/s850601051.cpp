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

#define P (1'000'000'007)

using vi = vector<int>;

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}

signed main() {
    int n, k;
    cin >> n >> k;

    vector<double> va;
    double max = 0.0;
    rep(i, n) {
        capi(a);
        va.push_back(a);
        chmax(max, (double)(a));
    }

    double d = max / 4.;
    double x = max / 2.;
    for (; d > 1E-9; d /= 2.) {
        int res = 0;
        rep(i, n) {
            res += ceil(va[i] / x) - 1.0;
        }
        if (res > k) {
            x += d;
        } else {
            x -= d;
        }
    }

    cout << (int)(ceil(x));

    return 0;
}