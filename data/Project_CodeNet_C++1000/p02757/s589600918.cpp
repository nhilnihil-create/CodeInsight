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
typedef pair<ll, ll> P;
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

# define int long long

int n, p;
string s;

ll cnt[10010];

int mod_pow(int x, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res = (res * x) % p;
        x = (x * x) % p;
        n >>= 1;
    }
    return res;
}

int mod_inverse(int x) {
    return mod_pow(x, p-2);
}

ll solve() {
    if (p == 2) {
        ll res = 0;
        for (int i = 0; i < n; i++) {
            int c = (int)(s[i] - '0');
            if (c % 2 == 0)
                res += i+1;
        }
        return res;
    }
    if (p == 5) {
        ll res = 0;
        for (int i = 0; i < n; i++) {
            int c = (int)(s[i] - '0');
            if (c == 0 || c == 5)
                res += i+1;
        }
        return res;
    }
    ll res = 0;
    int a = 0;
    int t = 1;
    for (int i = 0; i < n; i++) {
        int c = (int)(s[i] - '0');
        if (c % p == 0) res++;
        int r = (p - c % p) % p;
        int x = r * mod_inverse(10);
        x += p - a;
        x %= p;
        x *= mod_inverse(t);
        x %= p;
        res += cnt[x];
        int y = (p - a) % p;
        y *= mod_inverse(t);
        y %= p;
        cnt[y]++;
        a *= 10;
        a += c;
        a %= p;
        t *= 10;
        t %= p;
    }
    return res;
}

void input() {
    cin >> n >> p >> s;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
