#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    map<char,vector<int>> mp;
    rep(i,n) mp[s[i]].push_back(i);
    rep(i,m) if(mp[t[i]].empty()){
        cout << -1 << endl;
        return 0;
    }
    ll ans = 0;
    int now = -1;
    rep(i,m){
        char c = t[i];
        int idx = upper_bound(mp[c].begin(), mp[c].end(), now) - mp[c].begin();
        if(idx == mp[c].size()){
            ans += n - now + mp[c][0];
            now = mp[c][0];
        }
        else{
            ans += mp[c][idx] - now;
            now = mp[c][idx];
        }
    }
    cout << ans << endl;
}
