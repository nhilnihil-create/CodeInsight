#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i = 0; i < (ll) n; i++)
#define xrep(i,x,n) for(ll i = (ll) x; i < (ll) n; i++)
#define vl vector<long long>
#define all(A) A.begin(), A.end()

int main() {
    ll n; cin >> n;
    vl l(n);
    rep(i, n) cin >> l[i];

    sort(all(l));

    ll ans = 0;
    rep(i,n){
        xrep(j,i+1,n){
            auto ite = upper_bound(l.begin() + j + 1, l.end(), abs(l[i] - l[j]));
            auto ite2 = lower_bound(l.begin() + j + 1, l.end(), l[i] + l[j]);
            ans += ite2 - ite;
        }
    }

    cout << ans << endl;
}