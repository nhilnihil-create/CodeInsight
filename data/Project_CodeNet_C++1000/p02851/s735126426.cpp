#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 1001001001001001;

int main() {
    ll n; cin >> n;
    ll k; cin >> k;
    ll a[n];
    rep(i,n) {
        cin >> a[i];
        a[i] %= k;
    }
    ll b[n+1]; b[0] = 0;
    rep(i,n) {
        b[i+1] = (b[i]+a[i])%k;
    }
    ll c[n+1];
    ll x = k;
    while (x < 1000000) {
        x *= 2;
    }
    rep(i,n+1) {
        c[i] = (b[i]+x-i)%k;
    }
    //rep(i,n+1) {printf("%lld\n", c[i]);}
    map<ll, ll> mp;
    rep(i,min(k,n+1)) {
        mp[c[i]]++;
    }
    ll ans = 0;
    int idxr = (int)min(k,n+1);
    for (int i = 0; i+idxr < n+1; i++) {
        //printf("%d\n",i);
        ans += (ll)(mp[c[i]]-1);
        mp[c[i]]--;
        mp[c[i+idxr]]++;
        //for(auto itr = mp.begin(); itr != mp.end(); itr++) {printf("(%lld, %lld) %lld ", itr->first, itr->second, ans);}
        //printf("syakutori\n");
    }
    //cout << ans << endl;
    for (int i = n+1-idxr; i < n+1; i++) {
        //printf("%d\n",i);
        ans +=(ll)(mp[c[i]]-1);
        mp[c[i]]--;
        //for(auto itr = mp.begin(); itr != mp.end(); itr++) {printf("(%lld, %lld) %lld ", itr->first, itr->second, ans);}
        //printf("syakutori\n");
    }
    cout << ans << endl;
    return 0;
}
