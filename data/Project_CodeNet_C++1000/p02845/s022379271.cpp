#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;


ll a[100010];
ll x[100010];
ll y[100010];
ll z[100010];

int main(){
    ll n;
    cin >> n;
    rep(i, n) cin >> a[i];
    x[0] = 1;
    ll ans = 3;

    if (a[0] != 0){
        cout << 0 << endl;
        return 0;
    }

    for(int i = 1; i < n; i++){
        ll nxt = a[i];
        ll cnt = 0;
        ll nx = x[i-1], ny = y[i-1], nz = z[i-1];

        if (nx == nxt) cnt++;
        if (ny == nxt) cnt++;
        if (nz == nxt) cnt++;

        if (nx == nxt) nx++;
        else if (ny == nxt) ny++;
        else if (nz == nxt) nz++;

        x[i] = max({nx, ny, nz});
        z[i] = min({nx, ny, nz});
        y[i] = nx + ny + nz - x[i] - z[i];
        ans *= cnt;
        ans %= MOD;
    }

    // rep(i, n) cout << x[i] << " ";
    // cout << endl;
    // rep(i, n) cout << y[i] << " ";
    // cout << endl;
    // rep(i, n) cout << z[i] << " ";
    // cout << endl;

    cout << ans%MOD << endl;
    return 0;
}