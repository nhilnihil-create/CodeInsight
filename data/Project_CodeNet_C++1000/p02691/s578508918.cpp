#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using v  = vector<ll>;


int main(){
    int n; cin >> n;
    v a(n);
    
    rep(i,n)cin>>a[i];
    map<ll,v> l,r;
    
    rep(i,n){
        l[a[i]+i].push_back(i);
        r[i-a[i]].push_back(i);
    }
    
    ll ans = 0;
    
    for(auto p: l){//pair<ll, v>
        ll i = p.first;
        v vj = p.second;
        if(!r.count(i))continue;
        for(auto j: vj){//ll
            ll len = r[i].end() - upper_bound(r[i].begin(), r[i].end(), i);
            ans += len;
        }
    }
    
    cout << ans << endl;
    return 0;
}