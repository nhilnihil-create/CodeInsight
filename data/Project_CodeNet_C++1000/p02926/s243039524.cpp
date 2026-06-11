#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
#define ALL(v) v.begin(),v.end()
template<class T> inline bool chmax(T& a, T b) {if (a<b) {a=b; return true;} return false;}
template<class T> inline bool chmin(T& a, T b) {if (a>b) {a=b; return true;} return false;}

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vll x(n), y(n);
    REP(i, n) cin >> x[i] >> y[i];
    using D = double;
    D ans = 0;
    REP(i, n) {
        ll gx = x[i], gy = y[i];
        REP(k, 4) {
            {
                ll nx = -gy, ny=gx;
                gx = nx;
                gy = ny;
            }
            ll sx=0, sy=0;
            ll px=0, py=0;
            ll qx=0, qy=0;

            auto dot = [&](ll x1, ll y1, ll x2, ll y2){return x1*x2+y1*y2;};
            auto cross = [&](ll x1, ll y1, ll x2, ll y2){return x1*y2-y1*x2;};
            REP(j, n) {
                ll res = dot(x[j], y[j], gx, gy);
                if (res < 0) continue;
                else if (res > 0) {
                    sx += x[j];
                    sy += y[j];
                    continue;
                }
                if (cross(x[j], y[j], gx, gy) > 0) {
                    px += x[j];
                    py += y[j];
                } else {
                    qx += x[j];
                    qy += y[j];
                }
            }

            REP(t, 4) {
                D bx=sx, by=sy;
                if (t&1) bx += px, by += py;
                if (t&2) bx += qx, by += qy;
                chmax(ans, bx*bx+by*by);
            }
        }
    }
    cout << fixed << setprecision(12) << sqrt(ans) << '\n';
    return 0;
}
