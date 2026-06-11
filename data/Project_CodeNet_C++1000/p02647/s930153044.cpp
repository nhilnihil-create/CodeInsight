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
typedef pair<ll, ll> P;
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

ll n, k;
ll a[200100];

ll add[200100];

void solve() {
    for (int i = 0; i < k; i++) {
        memset(add, 0, sizeof(add));
        for (ll j = 0; j < n; j++) {
            add[max(0LL,j-a[j])]++;
            add[min(n,j+a[j]+1)]--;
        }
        bool f = false;
        for (int j = 0; j < n; j++) {
            a[j] = add[j];
            add[j+1] += add[j];
            if (a[j] < n) {
                f = true;
            }
        }
        if (!f) {
            for (int j = 0; j < n; j++) {
                a[j] = n;
            }
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i];
        if (i == n-1) cout << endl;
        else cout << " ";
    }
}

void input() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);

    input();
    solve();
}
