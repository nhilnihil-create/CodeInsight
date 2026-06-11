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
 
int main() {
    ll S;
    cin >> S;
    
    const ll m = 1e9;

    if(S <= m) {
        cout << 0 << " " << 0 << " " << 1 << " " << 0 << " " << 0 << " " << S << endl;
        re0;
    }

    if(S == 1e18) {
        ll x3 = 0, y3 = m;
        cout << 0 << " " << 0 << " " << m << " " << 0 << " " << 0 << " " << m << endl;
        re0;
    }
    
    cout << 0 << " " << 0 << " " << m << " " << 1 << " " << m - S%m << " " << S/m + 1 << endl;
    re0;
}