#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    if(p == 2){
        ll ans = 0;
        rep(i, 0, s.size()){
            if((s[i] - '0') % 2 == 0){
                ans += s.size() - i;
            }
        }
        cout << ans << endl;
    }else if(p == 5){
        ll ans = 0;
        rep(i, 0, s.size()){
            if(s[i] == '0' || s[i] == '5'){
                ans += s.size() - i;
            }
        }
        cout << ans << endl;
    }else{
        ll now = 0, ten = 1;
        map<ll, ll> mp;
        mp[0] = 1;
        rep(i, 0, s.size()){
            now += (s[i] - '0') * ten;
            now %= p;
            ten *= 10;
            ten %= p;
            mp[now]++;
        }
        ll ans = 0;
        for(auto p : mp) ans += p.second * (p.second - 1) / 2;
        cout << ans << endl;
    }
    return 0;
}