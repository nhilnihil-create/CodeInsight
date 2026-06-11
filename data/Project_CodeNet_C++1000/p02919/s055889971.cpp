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
        s.insert(x);
        auto it = s.find(x);
        ve<int> l(2,-1),r(2,n);
        rep(j,2){
            if(it == s.begin()) break;
            it--;
            l[j] = *it;
        }
        it = s.find(x);
        rep(j,2){
            it++;
            if(it == s.end()) break;
            r[j] = *it;
        }
        ans += (ll)i * (x-l[0]) * (r[1]-r[0]);
        ans += (ll)i * (l[0]-l[1]) * (r[0] - x);
    }
    cout << ans << endl;
    return 0;
}
