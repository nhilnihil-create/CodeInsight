#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <complex>
#include <string.h>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <iomanip>
#include <sys/time.h>
#include <tuple>
#include <random>
using namespace std;

#define endl '\n'
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define UNIQ(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef complex<double> comp;
typedef vector< vector<ld> > matrix;
struct pairhash {
public:
    template<typename T, typename U>
    size_t operator()(const pair<T, U> &x) const {
	size_t seed = hash<T>()(x.first);
	return hash<U>()(x.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
};
const int inf = 1e9 + 9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1);

int n;
ll a[200100], b[200100];

pair<ll, ll> calc(int k0, int k1) {
    ll lb = -1, ub = inf;
    while (ub - lb > 1) {
        ll mid = (lb + ub) / 2;
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] <= mid)
                cnt++;
        }
        if (cnt >= k0) {
            ub = mid;
        } else {
            lb = mid;
        }
    }
    ll l = ub;

    lb = -1; ub = inf;
    while (ub - lb > 1) {
        ll mid = (lb + ub) / 2;
        ll cnt = 0;
        for (int i = 0; i < n; i++) {
            if (mid <= b[i])
                cnt++;
        }
        if (cnt >= k1) {
            lb = mid;
        } else {
            ub = mid;
        }
    }
    ll r = lb;
    return make_pair(l, r);
}

ll solve() {
    if (n % 2 == 1) {
        pair<ll, ll> p = calc((n+1)/2, (n+1)/2);
        return p.second - p.first + 1;
    } else {
        pair<ll, ll> p0 = calc(n/2, n/2+1);
        pair<ll, ll> p1 = calc(n/2+1, n/2);
        return (p0.second+p1.second) - (p0.first+p1.first) + 1;
    }
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
