#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin >> n >> k;
    vector<int> p(n);
    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    for(int i = 0; i < n; i++) --p[i];
    for(int i = 0; i < n; i++) cin >> c[i];

    ll ans=-1e18;
    for(int si = 0; si < n; si++) {
        int x=si;
        vector<int> s;
        ll tot=0;
        while(true) {
            x=p[x];
            s.emplace_back(c[x]);
            tot+=c[x];
            if(x==si) break;
        }
        int l=s.size();
        ll t=0;
        for(int i = 0; i < l; i++) {
            t+=s[i];
            if(i+1 > k) break;
            ll now=t;
            if(tot>0){
                ll e=(k-i-1)/l;
                now+=tot*e;
            }
            ans=max(ans,now);
        }
    }
    cout << ans << "\n";

    return 0;
}