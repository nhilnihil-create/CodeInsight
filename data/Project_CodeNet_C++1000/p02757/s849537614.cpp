
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
    int n, p;
    cin >> n >> p;

    string s;
    cin >> s;

    int accu = 1;

    int res = 0;
    vi vp(p, 0);

    if (p != 2 && p != 5) {
        rep(i, n) {
            int pt = n - 1 - i;
            res += (s[pt] - '0') * accu;
            res %= p;
            ++vp[res];
            accu *= 10;
            accu %= p;
        }
    } else {
        int a = 0;
        rep(i, n) {
            if ((s[i] - '0') % p == 0) {
                a += i + 1;
            }
        }

        cout << a;
        return 0;
    }

    int ans = 0;

    rep(i, p) {
        if (i == 0) {
            ans += vp[i] * (vp[i] + 1) / 2;
        } else {
            ans += vp[i] * (vp[i] - 1) / 2;
        }
    }

    cout << ans;


    return 0;
}