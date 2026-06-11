#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
using ll = long long;

int main() {
    int n;
    cin >> n;
    vector<pair<ll,ll>>v(n);
    rep(i, 0, n){
        ll x, l;
        cin >> x >> l;
        v[i].first = x+l;
        v[i].second = x-l; 
    }
    sort(v.begin(), v.end());
    ll ans = 1;
    ll now = v[0].first;
    rep(i, 1, n){
        if(v[i].second < now)continue;
        ans++;
        now = v[i].first;
    }
    cout << ans << endl;
}