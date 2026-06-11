#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(n),b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];
    vector<ll> s(n+1),t(m+1);
    s[0] = 0;
    rep(i,n){
        s[i+1] = s[i]+a[i];
    }
    t[0]=0;
    rep(i,m){
        t[i+1] = t[i]+b[i];
    }
    int ans = 0;
    rep(i,n+1){
        ll res = k-s[i];
        if(res < 0) continue;
        int now = i;
        auto itr = upper_bound(t.begin(),t.end(),res);
        now += distance(t.begin(),itr)-1;
        ans = max(ans,now);
    }
    cout << ans << endl;
    return 0;
}