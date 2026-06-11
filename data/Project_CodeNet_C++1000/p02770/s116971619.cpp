#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>
#include <random>
#include <complex>
#include <functional>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

const ll inf = 1LL << 60;

template<class T> inline void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
template<class T> inline void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll k, q;
    cin >> k >> q;
    vec d(k);
    Rep (i, k) cin >> d[i];
    while (q--) {
        ll n, x, m;
        cin >> n >> x >> m;
        vec dm(k);
        Rep (i, k) dm[i] = d[i] % m;
        ll cnt = 0;
        ll tmp = 0;
        Rep (i, k) {
            if (dm[i] == 0) tmp++;
        }
        cnt += tmp * ((n-1) / k);
        Rep (i, (n-1) % k) {
            if (dm[i] == 0) cnt++;
        }

        // cout << "cnt(=):" << cnt << "\n";

        ll s = 0;
        Rep (i, k) {
            s += dm[i];
        }
        ll y = x;
        y += s * ((n-1) / k);
        Rep (i, (n-1) % k) {
            y += dm[i];
        }

        // cout << "x=" << x << " y=" << y << "\n";

        cnt += y / m - x / m;

        // cout << "cnt(>):" << cnt << "\n";
        cout << n - 1 - cnt << endl;
    }

}