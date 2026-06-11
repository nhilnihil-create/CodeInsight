#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

int main(){
    string s; ll k;
    cin >> s >> k;
    ll cnt = 0, ans = 0;
    char t = s[0];
    rep(i, s.length()){
        if(t == s[i]) cnt++;
        else {
            ans += cnt/2;
            cnt = 1;
            t = s[i];
        }  
    }
    if(t != ' ') ans += cnt/2;
    
    if(cnt == s.length()){
        ans = s.length() * k / 2;
    }else{
        ans *= k;
        if(s[0] == s[s.length()-1]){
            ll a = 0, b = 0;
            for(ll i = s.length()-1; i >= 0; --i){
                if(s[i] == s[s.length()-1]) a++;
                else break;
            }
            rep(i, s.length()){
                if(s[i] == s[0]) b++;
                else break;
            }
            ll c = (a/2 + b/2 - ((a+b)/2))*(k-1);
            ans -= c;
        }
    }
    cout << ans << endl;
    return 0;
}