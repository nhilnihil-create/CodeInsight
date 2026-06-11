#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector
#define chmin(x,y) x = min(x,y)

int main(){
    int n;
    cin >> n;
    ve<int> a(n),b(n+1);
    rep(i,n){
        cin >> a[i];
        b[a[i]] = (int)i;
    }
    ll ans = 0;
    set<int> s;
    s.insert(b[n]);
    s.insert(b[n-1]);
    ans += (ll)(n-1) * (1+*s.begin()) * (n-*next(s.begin()));
    s.insert(-1);
    s.insert(n);
    for (int i = n-2; i>0; i--) {
        int x = b[i];
        auto it = s.upper_bound(x);
        int y,z,w;
        y = *it;
        z = *prev(it);
        if(it != prev(s.end())){
            w = *next(it);
            ans += (ll)i * (x-z) * (w - y);
        }
        auto it2 = prev(it);
        if(it2 != s.begin()){
            ans += (ll)i * (z - *prev(it2)) * (y - x);
        }
        s.insert(x);
    }
    cout << ans << endl;
    return 0;
}
