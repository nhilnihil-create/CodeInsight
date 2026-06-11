#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    string s, t;
    cin>>s>>t;
    vector<vector<ll>> v(26);
    for (int i=0; i<s.size(); i++){
        v[s[i]-'a'].push_back(i);
    }
    ll ans = 0, idx = -1, cnt = 0;
    ll i = 0;
    ll flag = 0;
    while(i<t.size()){
        if (v[t[i]-'a'].size() == 0){ans = -1; break;}
        auto it = upper_bound(v[t[i]-'a'].begin(), v[t[i]-'a'].end(), idx);
        if (it == v[t[i]-'a'].end()){
            idx = -1;
            cnt++;
            continue;
        }
        idx = *it;
        i++;
        ans = cnt*s.size() + *it + 1;
        // cout<<ans<<endl;
    }
    cout<<ans<<endl;
}