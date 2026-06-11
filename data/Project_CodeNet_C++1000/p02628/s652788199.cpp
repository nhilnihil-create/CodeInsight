#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i = 0; i < (ll) n; i++)
#define xrep(i,x,n) for(ll i = (ll) x; i < (ll) n; i++)
#define vl vector<long long>
#define vs vector<string>
#define vvl vector<vector<long long>>
#define all(A) A.begin(), A.end()

int main() {
    ll n, k;
    cin >> n >> k;
    vl p(n);
    rep(i,n) cin >> p[i];

    sort(all(p));

    ll ans = 0;
    rep(i,k){
        ans += p[i];
    }

    cout << ans << endl;

}