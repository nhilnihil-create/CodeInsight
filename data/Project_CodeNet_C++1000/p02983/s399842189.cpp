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
    ll l, r;
    cin >> l >> r;

    ll ans = 2019;
    for(ll i = l; i < r; ++i){
        for(ll j = i+1; j <= r; ++j){
            ans = min(ans, (i*j)%2019);
            if(ans == 0){
                cout << 0 << endl;
                return 0;
            }
        }
    }

    cout << ans << endl;
}