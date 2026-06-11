#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    int n,p;
    cin >> n >> p;
    string str;
    cin >> str;
    reverse(str.begin(), str.end());
    vector<int> a(n), s(n+1);
    ll ans = 0;
    if(p==2 || p==5) {
        rep(i,n) {
            if((str[i]-'0')%p == 0) ans+=n-i;
        }
    } else {
        int pow_10_mod = 1;
        s[0] = 0;
        rep(i, n) {
            a[i] = ((str[i]-'0')*pow_10_mod)%p;
            s[i+1] = (s[i] + a[i])%p;
            pow_10_mod = (pow_10_mod*10)%p;
        }
        vector<ll> cnt(p);
        rep(i,n+1) {
            ans += cnt[s[i]];
            cnt[s[i]]++;
        }
    }
    cout << ans << endl;
}