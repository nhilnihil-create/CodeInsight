#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


int main(){
    int n;
    cin >> n;
    ll zmin = 2e9, zmax = -2e+9, wmin = 2e9, wmax = -2e+9;
    rep(i, n){
        ll x, y;
        cin >> x >> y;
        zmin = min(zmin, x + y);
        zmax = max(zmax, x + y);
        wmin = min(wmin, x - y);
        wmax = max(wmax, x - y);
    }
    cout << max(zmax - zmin, wmax - wmin) << endl;
    return 0;
}
