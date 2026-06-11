#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
using ll = long long;
using namespace std;

int main(){
    ll n; cin >> n;
    vector<ll> p(n);
    rep(i,n){
        ll a; cin >> a; a--;
        p[a] = i;
    }
    multiset<ll> check;
    check.insert(n);
    check.insert(n);
    check.insert(-1);
    check.insert(-1);

    ll ans = 0;
    rrep(i,n){
        ll k = p[i];
        auto iter = check.lower_bound(k);
        ll r1 = *iter;
        ll r2 = *(next(iter));
        iter--;
        ll l1 = *(iter);
        ll l2 = *(prev(iter));
        ans += (r1-k)*(l1-l2)*(i+1);
        ans += (r2-r1)*(k-l1)*(i+1);
        check.insert(k);
    }
    cout << ans << endl;
}