#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    int n;
    string s[100005];
    map<string, int> mp;
    cin >> n;
    rep(i,n){
        cin >> s[i];
        sort(s[i].begin(),s[i].end());
    }
    sort(s,s+n);

 
    rep(i,n-1){
        if(s[i] == s[i+1]) mp[s[i]]++;
    }

    ll ans = 0;
    for(auto m : mp){
        ll v = m.second + 1;
        ans += (v * (v - 1) / 2);
    }
    cout << ans << endl;
    return 0;
}