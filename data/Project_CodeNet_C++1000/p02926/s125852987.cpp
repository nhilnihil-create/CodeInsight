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
#define _USE_MATH_DEFINES
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef pair<double, ll> pdlg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef tuple<double, double, double> tddd;
typedef complex<double> xy_t;
typedef vector<ll> vll;
typedef vector< vector<ll> > matrix;
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

double cross_product (xy_t a, xy_t b) {
    return (conj(a) * b).imag();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed;
    cout << setprecision(12);
    ll N;
    cin >> N;
    xy_t pt[N];
    REP(i, 0, N) {
        ll x, y;
        cin >> x >> y;
        pt[i] = xy_t(x, y);
    }
    sort(pt, pt + N, [](xy_t a, xy_t b) {
        return arg(a) < arg(b);
    });
    double ans = 0;
    REP(i, 0, N) {
        REP(j, 1, N + 1) {
            ll rem = j;
            xy_t sum = 0;
            REP(k, i, N) {
                if (rem == 0) {
                    break;
                }
                sum += pt[k];
                rem--;
            }
            REP(k, 0, i) {
                if (rem == 0) {
                    break;
                }
                sum += pt[k];
                rem--;
            }
            ans = max(ans, abs(sum));
        }
    }
    cout << ans << endl;
}
