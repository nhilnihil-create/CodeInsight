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
    string s;
    cin >> s;

    vector<ll> lpos, rpos;
    rep(i, s.size()){
        if(s[i] == 'L')lpos.push_back(i);
        else rpos.push_back(i);
    }

    vector<ll> ans(s.size(), 0);
    rep(i, s.size()){
        if(s[i] == 'L'){
            ll pos = lower_bound(ALL(rpos), i) - rpos.begin() - 1;
            
            ll dif = i - rpos[pos];
            if(dif&1)ans[rpos[pos]+1]++;
            else ans[rpos[pos]]++; 
        }
        else {
            ll pos = lower_bound(ALL(lpos), i) - lpos.begin();

            ll dif = lpos[pos] -  i;
            if(dif&1)ans[lpos[pos]-1]++;
            else ans[lpos[pos]]++;
        }
    }

    rep(i, s.size())cout << ans[i] << " ";
}