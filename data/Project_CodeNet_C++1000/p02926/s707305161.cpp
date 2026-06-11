#include <iostream>
#include <iomanip>
#include <bitset>
#include <string>
#include <cstring>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<tuple>
#include<sstream>
#include<functional>
#include<list>
#include<queue>
using namespace std;
#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> p;
typedef vector<int> vec;
using Graph = vector<vector<int>>;
using graph = vector<vector<ll>>;

const long long INF = 1LL << 60;
const ll inf = 1e9;
const long long MOD = 1000000007;



int main() {
    long double t = acos(-1);
    long double ans = 0;
    ll n;
    cin >> n;
    vector<ll> x, y;
    rep(i, n) {
        ll a, b;
        cin >> a >> b;
        x.push_back(a); y.push_back(b);
    }
    vector<pair<long double,ll>> vx(n*2),vy(n*2);
    rep(i, n) {
        vx[i].first = atan2(y[i], x[i]); vx[i].second = x[i];
        vy[i].first = atan2(y[i], x[i]); vy[i].second = y[i];
    }
    rep(i, n) {
        vx[i+n].first = atan2(y[i], x[i])+t*2; vx[i+n].second = x[i];
        vy[i+n].first = atan2(y[i], x[i])+t*2; vy[i+n].second = y[i];
    }
    sort(all(vx)); sort(all(vy));
    vector<long double> rad(n*2);
    vector<ll> X(n*2), Y(n*2);
    X[0] = vx[0].second; Y[0] = vy[0].second;
    rep(i, n*2) {
        rad[i] = vx[i].first;
        if (i != 0) {
            X[i] = X[i - 1] + vx[i].second; Y[i] = Y[i - 1] + vy[i].second;
        }
    }
    rep(i, n) {
        int a = lower_bound(all(rad), rad[i]+t-1)-rad.begin();
        int b= lower_bound(all(rad), rad[i] + t + 1) - rad.begin();
        repd(j, a, b + 1) {
            if (i != 0)ans = max((long double)sqrt((X[j - 1] - X[i - 1]) * (X[j - 1] - X[i - 1]) + (Y[j - 1] - Y[i - 1]) * (Y[j - 1] - Y[i - 1])), ans);
            else ans = max(ans, (long double)sqrt(X[j - 1] * X[j - 1] + Y[j - 1] * Y[j - 1]));
        }
    }
    printf("%0.20Lf\n", ans);
    return 0;
}