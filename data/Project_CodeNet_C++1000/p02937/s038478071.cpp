#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(){
    string s0,t;
    cin >> s0 >> t;
    vector<set<int>> s(26);
    int n = s0.size();
    rep(i,n){
        s[s0[i]-'a'].insert(i);
    }

    ll ans = 0;
    int now=-1;
    rep(i,t.size()){
        int c = t[i]-'a';
        if(s[c].empty()){ans=-1;break;}
        auto it = s[c].upper_bound(now);
        if(it == s[c].end()){
            now = *s[c].begin();
            ans += n;
        }else{
            now = *it;
        }
    }
    if(ans!=-1)ans+=now+1;
    cout << ans << endl;
    return 0;
}