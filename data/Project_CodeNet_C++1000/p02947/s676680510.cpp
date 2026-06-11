#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e12 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

int main(){
    ll n;
    cin >> n;

    map<string, ll> mp;
    rep(i, n){
        string s;
        cin >> s;
        sort(ALL(s));
        if(mp.count(s) > 0)mp[s]++;
        else mp[s] = 1;
    }

    ll ans = 0;
    all_map(itr, mp){
        ans += itr->second*(itr->second-1) /2;
    }

    cout << ans << endl;
}