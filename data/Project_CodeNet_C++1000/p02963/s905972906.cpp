#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
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
const ll MAX_N = 100010;

ll ceil(ll a, ll b) {  // a÷b以上の最小の整数
    if(b == 0) {
        return 0;
    }
    return (a+b-1)/b;
}
 
int main() {
    ll S;
    cin >> S;

    ll x1 = 0, y1 = 0;

    const ll m = 1e9;

    if(S <= m) {
        cout << x1 << " " << y1 << " " << 1 << " " << 0 << " " << 0 << " " << S << endl;
        re0;
    }

    ll x2 = m, y2 = 1;

    if(S == 1e18) {
        ll x3 = 0, y3 = m;
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
        re0;
    }
    
    ll y3 = S/m + 1;
    ll z = S%m;
    ll x3 = m - z;
    
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
    re0;
}