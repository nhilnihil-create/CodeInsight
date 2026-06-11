#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, n) for (ll i = n-1; i >= 0; i--)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define repd2(i, s, n) for (ll i = n-1; i >= (s); i--)

int main() {
    ll n;
    cin >> n;
    vector<ll> L(n);
    rep(i, n) cin >> L[i];
    ll ans = 0;
    rep(i, n){
        rep2(j, i+1, n){
            rep2(k, j+1, n){
                ll a = L[i];
                ll b = L[j];
                ll c = L[k];
                if (a!=b&&b!=c&&c!=a&&a+b>c&&b+c>a&&c+a>b){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}