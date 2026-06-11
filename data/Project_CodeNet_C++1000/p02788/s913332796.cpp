#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;


int main(){
    ll n, d, a; cin >> n >> d >> a;
    vector<pair<ll,ll>> data(n);
    rep(i,n){
        ll aa, bb; cin >> aa >> bb;
        data[i] = make_pair(aa,bb);
    }
    sort(all(data));
    vector<ll> x(n), h(n);
    rep(i,n){
        x[i] = data[i].first;
        h[i] = data[i].second;
    }

    ll ans = 0;
    vector<ll> attack(n+1,0);
    rep(i,n){
        if(h[i]-attack[i] <= 0){
            attack[i+1] += attack[i];
            continue;
        }
        ll count = (h[i]-attack[i]+a-1)/a;
        ans += count;
        ll k = upper_bound(all(x),x[i]+2*d)-x.begin();
        attack[i] += a*count;
        attack[k] -= a*count;
        attack[i+1] += attack[i];
    }
    cout << ans << endl;
}