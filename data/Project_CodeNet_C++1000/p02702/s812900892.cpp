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
    string s;
    cin >> s;
    map<ll,ll> m;
    ll ans = 0;
    ll temp = 1;
    ll memo = 0;
    m[0] = 1;

    rep(i,0,s.size()){
        memo += temp * (ll)(s[s.size()-i-1] - '0');
        memo %= 2019;
        temp *= 10; temp %= 2019;

        if(m.count(memo) == 0){
            m[memo] = 1;
        }
        else{
            m[memo]++;
        }
    }

    rep(i,0,2019) if(m.count(i) != 0) ans += m[i]*(m[i]-1)/2;
    cout << ans << endl;
    return 0;
}
