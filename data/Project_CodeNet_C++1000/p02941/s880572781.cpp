// 見せてやるぜ、奇跡ってやつをよぉ……
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
#include <functional>
#include <cassert>
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
#define DEBUG_VLL(vec) REP(i, vec.size()) cerr<<vec[i]<<(i==vec.size()-1?'\n':' ');

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vll a(n), b(n);
    priority_queue< P<ll, ll> > pq;
    REP(i, n) cin >> a[i];
    REP(i, n) {
        cin >> b[i];
        if (a[i] != b[i]) pq.push(make_pair(b[i], i));
    }
    ll ans = 0;
    while (!pq.empty()){
        P<ll, ll> q = pq.top(); pq.pop();
        if (b[(q.second-1+n)%n] + b[(q.second+1)%n] >= b[q.second]) {
            cout << -1 << '\n';
            return 0;
        }
        if ((b[q.second]-a[q.second])%(b[(q.second-1+n)%n] + b[(q.second+1)%n]) == 0) {
            ans += (b[q.second]-a[q.second]) / (b[(q.second-1+n)%n] + b[(q.second+1)%n]);
            b[q.second] = a[q.second];
            continue;
        }
        ans += b[q.second] / (b[(q.second-1+n)%n] + b[(q.second+1)%n]);
        b[q.second] %= (b[(q.second-1+n)%n] + b[(q.second+1)%n]);
        if (b[q.second] < a[q.second]) {
            cout << -1 << '\n';
            return 0;
        }
        pq.push(make_pair(b[q.second], q.second));
    }
    cout << ans << '\n';
    return 0;
}
