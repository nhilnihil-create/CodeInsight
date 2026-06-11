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
#include <random>
using namespace std;

#define endl '\n'
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define UNIQ(v) (v).erase(unique((v).begin(), (v).end()), (v).end())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
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

int n, m, x;
int c[12], a[12][12];

int solve() {
    int res = inf;
    int r[m];
    for (int i = 1; i < (1<<n); i++) {
        memset(r, 0, sizeof(r));
        int d = 0;
        for (int j = 0; j < n; j++) {
            if ((i>>j)&1) {
                d += c[j];
                for (int k = 0; k < m; k++) {
                    r[k] += a[j][k];
                }
            }
        }
        bool f = true;
        for (int j = 0; j < m; j++) {
            if (r[j] < x) {
                f = false;
                break;
            }
        }
        if (f) {
            res = min(res, d);
        }
    }
    return (res < inf ? res : -1);
}

void input() {
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    cout << solve() << endl;
}
