
#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
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

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}

signed main() {
    capi(n);
    int v[10][10] = {0};

    int d = 1;
    int r = 1;
    rep(i, n) {
        if (i + 1 >= r * 10) {
            r *= 10;
            ++d;
        }
        ++v[(i + 1) / r][(i + 1) % 10];
    }

    int ans = 0;
    rep(i, 10) {
        rep(j, 10) {
            ans += v[i][j] * v[j][i];
        }
    }

    cout << ans;

    return 0;
}