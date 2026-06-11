#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    string s,t; cin>>s>>t;
    int n = s.size(),m = t.size();
    vector<vector<int>> moji(26);
    rep(i,n) moji[s[i]-'a'].push_back(i);
    rep(i,n) moji[s[i]-'a'].push_back(i+n);
    ll ans = 0;
    int p = 0;
    rep(i,m){
        int c = t[i] - 'a';
        if(moji[c].size()==0){
            cout << -1 << endl;
            return 0;
        }

        p = *lower_bound(moji[c].begin(),moji[c].end(),p)+1;
        if(p>=n){
            p -= n;
            ans += n;
        }
    }
    ans += p;
    cout << ans << endl;
    return 0;
}