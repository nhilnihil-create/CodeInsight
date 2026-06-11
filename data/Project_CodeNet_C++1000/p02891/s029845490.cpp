#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;

int main(){
    string s;
    cin >> s;
    ll k;
    cin >> k;
    ll n = s.size()-1;
    ll ans = 0;
    bool same = true;
    ll now = 1;
    vector<ll> can;
    bool all = true;
    for(ll i = 0; i < n; i++){
        if(s[i] == s[i+1] && same){
            now++;
        } else if(s[i] == s[i+1]){
            now++;
            same = true;
        } else {
            all = false;
            can.push_back(now);
            now = 1;
        }
    }
    if(all){
        cout << s.size()*k/2 << endl;
        return 0; 
    }
    if(n > 0 && s[n-1] == s[n]) can.push_back(now);
    same = false;
    if(s[0] == s[n]) same = true;
    for(auto p:can){
        ans += p/2;
    }
    ans *= k;
    if(can.empty()){
        cout << k/2 << endl;
        return 0;
    }
    if(can[0]%2 != 0 && can.back()%2 != 0 && same) ans += k-1;
    cout << ans << endl;
}