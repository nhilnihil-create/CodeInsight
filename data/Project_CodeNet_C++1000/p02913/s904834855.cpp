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

ll z_alg(string s){
    ll a[s.size()] = {};
    ll c = 0;
    ll ret = 0;

    for(ll i = 1; i < s.size(); ++i){
        if(i + a[i-c] < c + a[c]){
            a[i] = a[i-c];
        }
        else {
            ll j = max(0LL, c + a[c] - i);
            while(i + j < s.size() && s[j] == s[i + j])++j;
            a[i] = j;
            c = i;
        }

        ret = max(ret, min(i, a[i]));
    }

    return ret;
}

int main(){
    ll n;
    string s;
    cin >> n >> s;
    
    ll ans = 0;
    while(!s.empty()){
        ans = max(ans, z_alg(s));
        s.erase(s.begin());
    }

    cout << ans << endl;
}