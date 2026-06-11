#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector
#define chmin(x,y) x = min(x,y)

int main(){
    int n,k;
    cin >> n >> k;
    ve<int> a(n);
    int s = 0;
    rep(i,n){
        cin >> a[i];
        s += a[i];
    }
    set<int> fac;
    for (int i = 1; i*i <= s; i++) {
        if(s%i == 0){
            fac.insert(i);
            fac.insert(s/i);
        }
    }
    int ans = 1;
    
    for(int x: fac){
        int memo = 2e9;
        ve<int> m(n);
        rep(j,n){
            m[j] = a[j] % x;
        }
        sort(m.begin(), m.end());
        ve<int> sl(n+1),sr(n+1);
        sl[0] = 0; sr[0] = 0;
        rep(j,n) sl[j+1] = sl[j] + m[j];
        rep(j,n) sr[j+1] = sr[j] + (x-m[n-1-j]);
        rep(j,n+1) {
            if(sl[j] == sr[n-j]){
                memo = sl[j];
                break;
            }
        }
        if(memo <= k){
            ans = max(ans,x);
        }
    }
    cout << ans << endl;
    return 0;
}
