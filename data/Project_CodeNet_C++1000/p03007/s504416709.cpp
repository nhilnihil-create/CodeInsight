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

    vl a(n+1);
    exrep(i, 1, n) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());

    ll Q;  // aの0未満の要素の個数
    if(0 <= a[1]) {
        Q = 1;
    }
    else if(a[n] < 0) {
        Q = n-1;
    }
    else {
        exrep(i, 2, n) {
            if(0 <= a[i]) {
                Q = i-1;
                break;
            }
        }
    }

    vl x(n), y(n);
    exrep(i, Q+1, n-1) {
        x[i-Q] = a[1];
        y[i-Q] = a[i];
        a[1] -= a[i];
    }
    exrep(i, 1, Q) {
        x[(n-1) - Q + i] = a[n];
        y[(n-1) - Q + i] = a[i];
        a[n] -= a[i];
    }
    
    out(a[n]);
    exrep(i, 1, n-1) {
        cout << x[i] << " " << y[i] << "\n";
    }
    
    re0;
}