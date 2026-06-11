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
    string s, t;
    cin >> s >> t;

    vector<vector<ll>> vec(26);
    rep(i, s.size()){
        vec[s[i]-'a'].push_back(i+1);
    }

    ll ans = 0;
    ll pos = -1;
    for(char c : t){
        if(vec[c-'a'].empty()){
            cout << -1 << endl;
            return 0;
        }

        auto itr = upper_bound(ALL(vec[c-'a']), pos);
        if(itr == vec[c-'a'].end()){
            ans += s.size();
            pos = vec[c-'a'].front();
        }
        else pos = *itr;
    }
    
    cout << ans + pos;
}
