#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#include <complex>
#include <unistd.h>
#include <cassert>
#include <cctype>
#include <random>
#include <time.h>
#include <functional>
#define _USE_MATH_DEFINES
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef pair<double, ll> pdlg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef tuple<ll, ll, ll, ll> tlglglglg;
typedef tuple<double, double, double> tddd;
typedef complex<double> xy_t;
typedef vector<ll> vll;
typedef vector< vector<ll> > matrix;
typedef unsigned int uint;
typedef unsigned long long ull;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template <class T> using VVV = V<VV<T>>;
#define REP(i, x, y) for(ll i = (ll)x; i < (ll)y; i++)
#define DREP(i, x, y, d) for(ll i = (ll)x; i < (ll)y; i += (ll)d)
#define PER(i, x, y) for(ll i = (ll)x; i > (ll)y; i--)
#define DPER(i, x, y, d) for(ll i = (ll)x; i > (ll)y; i -= (ll)d)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
int iinf = intmax / 8;
ll inf = llmax / 8;
double eps = 1e-12;
void yesno(bool ok, string yes = "Yes", string no = "No") {
    if (ok) {
        cout << yes << endl;
    } else {
        cout << no << endl;
    }
}

vll nums(300010, 0);
vll ds(300010, 0);
vll kds(300010, 0);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vll A(N);
    REP(i, 0, N) {
        cin >> A[i];
        nums[A[i]]++;
    }
    REP(i, 0, N + 1) {
        ds[nums[i]]++;
    }
    REP(i, 0, N + 1) {
        kds[i] = ds[i] * i;
        if (i > 0) {
            kds[i] += kds[i - 1];
        }
    }
    PER(i, N - 1, -1) {
        ds[i] += ds[i + 1];
    }
    vll f(N + 1);
    f[0] = inf;
    REP(i, 1, N) {
        f[i] = (kds[i] + i * ds[i + 1]) / i;
    }
    f[N] = kds[N] / N;
    ll ans = N;
    REP(i, 1, N + 1) {
        while (i > f[ans]) {
            ans--;
        }
        cout << ans << endl;
    }
}
