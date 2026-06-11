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
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
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
    ll n;
    cin >> n;

    vl a(n);
    rep(i, n) {
        cin >> a[i];
    }
    sort(all(a));

    ll k;  // aの0未満の要素の個数
    if(0 <= a[0]) {
        k = 1;
    }
    else if(a[n-1] < 0) {
        k = n-1;
    }
    else {
        exrep(i, 1, n-1) {
            if(0 <= a[i]) {
                k = i;
                break;
            }
        }
    }

    vl x(n-1), y(n-1);
    exrep(i, k, n-2) {
        x[i-k] = a[0];
        y[i-k] = a[i];
        a[0] -= a[i];
    }
    rep(i, k) {
        x[(n-1) - k + i] = a[n-1];
        y[(n-1) - k + i] = a[i];
        a[n-1] -= a[i];
    }
    
    out(a[n-1]);
    rep(i, n-1) {
        cout << x[i] << " " << y[i] << "\n";
    }
    
    re0;
}