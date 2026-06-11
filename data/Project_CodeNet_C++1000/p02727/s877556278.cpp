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
const ll inf = 1e18 + 9;
const ll mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = acos(-1);

int x, y, a, b, c;
vector<ll> p, q, r;

ll solve() {
    sort(RALL(p));
    sort(RALL(q));
    sort(RALL(r));
    vector<ll> vec;
    for (int i = 0; i < x; i++) {
        vec.push_back(p[i]);
    }
    for (int i = 0; i < y; i++) {
        vec.push_back(q[i]);
    }
    sort(ALL(vec));
    int l = min((int)vec.size(), c);
    for (int i = 0; i < l; i++) {
        vec[i] = max(vec[i], r[i]);
    }

    ll res = 0;
    for (ll v : vec) {
        res += v;
    }
    return res;
}

void input() {
    cin >> x >> y >> a >> b >> c;
    p = vector<ll>(a);
    q = vector<ll>(b);
    r = vector<ll>(c);
    for (int i = 0; i < a; i++) cin >> p[i];
    for (int i = 0; i < b; i++) cin >> q[i];
    for (int i = 0; i < c; i++) cin >> r[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
