#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr long long MOD = 1000000007;
constexpr long long INF = 1LL << 60;
const long double PI = acosl(-1.0);
constexpr long double EPS = 1e-11;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
int main(){
    string s;
    ll k;
    cin >> s >> k;
    ll n = s.size();
    map<char, ll> mp;
    for (ll i = 0; i < n;i++){
        mp[s[i]]++;
    }
    if(mp.size()==1){
        cout << k * n / 2 << endl;
    }
    else if(s[0]!=s[n-1]){
        ll tmp = 1;
        ll ans = 0;
        for (ll i = 0; i < n - 1; i++) {
            while (s[i] == s[i + 1]) {
                tmp++;
                i++;
            }
                ans += tmp / 2;
                tmp = 1;
            }
        cout << ans*k << endl;
    }
    else {
        ll left = 0, right = 0;
        for (ll i = 0; i < n;i++){
            if(s[i]!=s[0]){
                left=i;
                break;
            }
        }
        for (ll i = n - 1; i >= 0;i--){
            if(s[i]!=s[n-1]){
                right = i;
                break;
            }
        }
        ll tmp = 1;
        ll ans = 0;
        for (ll i = 0; i < n - 1; i++) {
            while (s[i] == s[i + 1]) {
                tmp++;
                i++;
            }
                ans += tmp / 2;
                tmp = 1;
        }
        cout << ans * k - (k - 1) * (left / 2 + (n - right - 1) / 2 - (left + n - right-1) / 2) << endl;
    }
}