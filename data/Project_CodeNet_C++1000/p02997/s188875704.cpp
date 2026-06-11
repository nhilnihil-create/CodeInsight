#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(pos,mp) for(ll pos=mp.begin();pos!=mp.end();pos -++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

int main(){
    ll n, k;
    cin >> n >> k;

    if(k > (n-1)*(n-2)/2){
        cout << -1 << endl;
        return 0;
    }

    cout << n*(n-1)/2 - k << endl;

    for(ll i = 1; i <=n; ++i){
        for(ll j = i+1; j <=n; ++j){
            if(i != 1 && k > 0){
                k--;
                continue;
            }

            cout << i << " " << j << endl;
        }
    }
}