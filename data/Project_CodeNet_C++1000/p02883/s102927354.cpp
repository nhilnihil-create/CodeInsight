#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF 1e18
#define INF 1e9
using namespace std;

#define fs first
#define sc second

using P = pair<ll,ll>;
using Pll = pair<P,ll>;
using PQ = priority_queue<P,vector<P>,greater<P>>;


const ll MOD = 1e9+7;
 

signed main(){
    ll n,k;
    cin >> n >> k;
    ll a[n],f[n];
    rep(i,0,n) cin >> a[i];
    rep(i,0,n) cin >> f[i];

    sort(a,a+n);
    sort(f,f+n,greater<ll>());
    ll ok = (ll)(1e16),ng = -1;
    while(abs(ok-ng) > 1){
        ll mid = (ok+ng)/2;
        ll cnt = 0;
        rep(i,0,n){
            cnt += max((ll)ceil((double)a[i] - (double)mid/(double)f[i]),0LL);
        }

        if(cnt <= k){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }

    cout << ok << endl;
    return 0;
}
