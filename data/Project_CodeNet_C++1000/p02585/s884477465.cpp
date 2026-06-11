#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int n,k;
    cin >> n >> k;
    vector<ll> p(n);
    vector<ll> c(n);
    ll ans = -1e18;
    rep(i,n) cin >> p.at(i);
    rep(i,n) cin >> c.at(i);
    rep(i,n) p.at(i)--;

    rep(si,n){
        // find cycle
        int x = si;
        vector<int> cycle_score;
        ll tot = 0;
        while(true){
            x = p.at(x);
            cycle_score.push_back(c.at(x));
            tot += c.at(x);
            if(x == si) break;
        }
        int cycle_size = cycle_score.size();
        ll tmp = 0;
        rep(i,cycle_size){
            tmp += cycle_score.at(i);
            if(i + 1 > k) break;
            ll now = tmp;
            if(tot > 0){
                ll e = (k - (i+1)) / cycle_size;
                now += tot * e; 
            }
            ans = max(ans,now);
        }
    }
    cout << ans << endl;
}