#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,l,r) for (ll i = (ll)l; i < (ll)(r); i++)

int main(){
    ll N; cin >> N;
    map<ll,ll> md,ms;
    rep(i,0,N){
        ll a; cin >> a;
        md[i+1-a]++ ; ms[i+1+a]++;
    }
    ll ans = 0;
    for(auto &d : md){
        ans += d.second * ms[d.first];
    }
    cout << ans << endl;
}