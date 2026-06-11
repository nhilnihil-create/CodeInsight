#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const double pi = acos(-1);

int main() {
    ll n;
    cin >> n;

    vector<P> p(n);
    rep(i, n) {
        ll x, y;
        cin >> x >> y;
        p[i] = make_pair(x, y);
    }
    sort(all(p));

    map<P, ll> mp;
    exrep(i, 0, n-2) {
        exrep(j, i+1, n-1) {
            ll dx = p[j].first - p[i].first;
            ll dy = p[j].second - p[i].second;
            mp[make_pair(dx, dy)]++;
        }
    }

    ll ma = 0;
    for(auto x : mp) {
        chmax(ma, x.second);
    }
    
    out(n - ma);
    re0;
}