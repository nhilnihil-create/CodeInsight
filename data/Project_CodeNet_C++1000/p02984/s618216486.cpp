#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

int main(){
    ll n;
    cin >> n;

    ll a[n];
    ll x = 0;
    rep(i, n){
        cin >> a[i];
        x += a[i];
        if(i & 1)x -= 2*a[i];
    }

    ll ans[n];
    ans[0] = x;
    ans[n-1] = 2*a[n-1] - ans[0];
    for(ll i = 1; i < n; ++i){
        ans[i] = 2*a[i-1] - ans[i-1];
    }

    rep(i, n)cout << ans[i] << " ";
}