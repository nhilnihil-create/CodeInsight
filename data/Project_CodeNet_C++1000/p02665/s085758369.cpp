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

ll ceil(ll a, ll b) {  // a÷b以上の最小の整数
    if(b == 0) {
        return 0;
    }
    return (a+b-1)/b;
}

int main() {
    ll n;
    cin >> n;

    vl a(n+1);
    rep(i, n+1) {
        cin >> a[i];
    }

    vl x(n+1), y(n+1);
    x[n] = y[n] = a[n];
    for(ll i = n-1; i >= 0; i--) {
        x[i] = ceil(x[i+1], 2) + a[i];
        y[i] = y[i+1] + a[i];
    }

    if(1 < x[0]) {
        out(-1);
        re0;
    }
    
    vl z(n+1);
    z[0] = 1;
    ll ans = 1;
    exrep(i, 1, n) {
        z[i] = min(y[i], 2*(z[i-1] - a[i-1]));
        ans += z[i];
    }

    out(ans);
    re0;
}