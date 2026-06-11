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


ll n, k;
vector<ll> a, f;

bool isOK(ll x) {
    ll cost = 0;
    rep(i, n){
        cost += max(0ll, a[i] -  x/f[i]);
    }

    if (cost <= k) return true;
    else return false;
}

ll binary_search() {
    ll ng = -1;
    ll ok = 1e+18+7;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;

        if (isOK(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}



int main(){
    cin >> n >> k;
    rep(i, n){
        ll t;
        cin >> t;
        a.push_back(t);
    }
    rep(i, n){
        ll t;
        cin >> t;
        f.push_back(t);
    }

    sort(a.rbegin(), a.rend());
    sort(f.begin(), f.end());

    cout << binary_search() << endl;

    return 0;
}
