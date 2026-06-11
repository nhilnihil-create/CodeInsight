#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(ll i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll s = 0;
    
    rep(i, n) s ^= a[i];
    ll ans = s;
    
    ll bit = 0;
    rep(i, n) {
        ll j = 0;
        while (a[i]>>j) j++;
        j--;
        bit = max(bit, j);
    }
    rep(i, n) a[i] &= ~s;

    ll r = 0;
    //debug(ans);
    //debug(bit);
    
    
    for (ll i=bit; i>=0; i--) {
        //if (s>>i&1) continue;
        if (r==n) break;
        ll j = r;
        while (j<n && ((a[j]>>i&1)==0)) j++;
        if (j==n) continue;
        swap(a[r], a[j]);
        //debug(r);
        //debug(j);
        rep(k, n) {
            if (k==r) continue;
            if (a[k]>>i&1) a[k] ^= a[r];
        }
        r++;
        //ans += (1LL<<(i+1));
        //debug(i);
        //debug(r);
        //debug(ans);
        //rep(ii, n) debug(a[ii]);
    }
    ll x = 0;
    rep(i, r) {
        x ^= a[i];
    }
    ans += x*2;

    

    
    cout << ans << endl;
    return 0;
}
