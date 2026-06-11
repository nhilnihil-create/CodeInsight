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
typedef pair<ll, int> P;
typedef tuple<int, int, int> T;
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

ll n;

map<ll, int> prime_factor(ll n) {
    map<ll, int> res;
    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            res[i]++;
            n /= i;
        }
    }
    if (n != 1) res[n] = 1;
    return res;
}

int solve() {
    if (n == 1) return 0;
    map<ll, int> m = prime_factor(n);
    int res = 0;
    for (auto v : m) {
        int i = 1;
        int k = v.second;
        while (i <= k) {
            k -= i;
            i++;
            res++;
        }
    }
    return res;
}

void input() {
    cin >> n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
