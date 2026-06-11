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
#define dev(v, m, n) for(int i=0;i<n;++i){for(int j=0;j<m;++j){cout<<"|"<<v[j][i];}cout<<"|"<<endl;}

using vi = vector<int>;

#define P (1'000'000'007)

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}

signed main() {
    capi(n);

    vi vf;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) vf.push_back(i);
    }

    int ans = 0;
    for (auto f: vf) {
        int a = n;

        while (a >= 1) {
            if (a % f == 0) {
                a /= f;
            } else if (a % f == 1) {
                ++ans;
                break;
            } else {
                break;
            }
        }
    }

    vi va;
    int x = n - 1;
    int r = 1;
    for (int i = 2; i <= sqrt(n - 1); ++i) {
        int rep = 1;
        while (x % i == 0) {
            x /= i;
            ++rep;
        }

        r *= rep;
    }

    if (x > 1) r *= 2;

    cout << ans + r;

    return 0;
}