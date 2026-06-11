#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){

    ll n,k;
    cin >> n >> k;
    vector<vector<ll>> cost(n);
    vector<ll> p(n),c(n), sum(n,0);
    for(ll i = 0; i < n; i++) cin >> p[i], p[i]--;
    for(ll i = 0; i < n; i++) cin >> c[i];
    
    for(ll i = 0; i < n; i++){
        ll now = i;
        while(true){
            now = p[now];
            cost[i].push_back(c[now]);
            sum[i] += c[now];
            if(now == i) break;
        }
    }

    auto calc = [&](ll i,ll n,bool z){
        ll mx = cost[i][0];
        ll tmp = 0;
        if(z) mx = max(0ll,mx);
        for(ll j = 0; j < n; j++){
            tmp += cost[i][j%cost[i].size()];
            mx = max(mx,tmp);
        }  
        return mx;
    };

    ll ans = -mod*mod;

    for(ll i = 0; i < n; i++){
        ll cs = cost[i].size();
        ll fir = calc(i,min(cs,k),false);
        ans = max(ans,fir);
        if(sum[i] <= 0) continue;
        ll can;
        if(cs <= k && k <= 2*cs){
            can = calc(i,k,false);
        } else {
            can = sum[i]*((k/cs)-1);
            int m = k%cs+cs;
            can += calc(i,m,true);
        }
        ans = max(can,ans);
    }

    cout << ans << endl;


    return 0;
}