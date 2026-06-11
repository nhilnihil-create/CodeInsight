#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    string s,t;
    cin >> s >> t;
    set<char> sset;
    for(i = 0;i < s.size();++i){
        sset.insert(s.at(i));
    }
    for(i = 0;i < t.size();++i){
        if(!sset.count(t.at(i))){
            cout << -1 << endl;
            return 0;
        }
    }
    map<char,vector<ll>> mp;
    for(i = 0;i < s.size();++i){
        mp[s.at(i)].push_back(i);
    }
    ll ans = 0;
    ll now = 0;
    i = 0;
    while(i < t.size()){
        auto x = lower_bound(all(mp[t.at(i)]), now);
        if(x == mp[t.at(i)].end()){
            ans /= s.size();
            ans = (ans+1)*s.size();
            now = 0;
            continue;
        }else{
            now = *x+1;
            ++i;
        }
    }
    ans += now;
    cout << ans << endl;
    return 0;
}