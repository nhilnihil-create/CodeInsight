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

    ll M;
    vl x(n-1), y(n-1);
    if(a[n-1] <= 0) {  // すべて0以下のとき
        M = a[n-1];
        rep(i, n-1) {
            x[i] = M;
            y[i] = a[i];
            M -= a[i];
        }
    }
    else if(0 <= a[0]) {  // すべて0以上のとき
        M = a[0];
        rep(i, n-2) {
            x[i] = M;
            y[i] = a[i+1];
            M -= a[i+1];
        }
        x[n-2] = a[n-1];
        y[n-2] = M;
        M = a[n-1] - M;
    }
    else {  // 正負の数がともにあるとき
        sort(rall(a));
        ll k;  // 0以上の数はk個ある
        rep(i, n) {
            if(a[i] < 0) {
                k = i;
                break;
            }
        }
        ll t = a[n-1];
        rep(i, k-1) {
            x[i] = t;
            y[i] = a[i+1];
            t -= a[i+1];
        }
        M = a[0];
        x[k-1] = M;
        y[k-1] = t;
        M -= t;
        exrep(i, k, n-2) {
            x[i] = M;
            y[i] = a[i];
            M -= a[i];
        }
    }

    out(M);
    rep(i, n-1) {
        cout << x[i] << " " << y[i] << "\n";
    }

    re0;
}