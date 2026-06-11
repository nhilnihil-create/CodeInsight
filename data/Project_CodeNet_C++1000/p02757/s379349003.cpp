#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

const int mod = 2019;
int main() {
    ll n,p;
    cin >> n >> p;
    string s;
    cin >> s;
    ll ans = 0;
    if(p==2 || p==5) {
        rep(i,n) if((s[n-1-i]-'0')%p == 0) ans += n-i; 
        cout << ans << endl;
        return 0;   
    }
    ll cur = 0;
    ll fac = 1;
    map<ll,ll> mp;
    mp[0] = 1;
    rep(i,n) {
        cur += (s[n-1-i]-'0')*fac;
        cur = cur%p;
        mp[cur]++;
        fac = fac*10%p;
    }
    rep(i,p) ans += mp[i]*(mp[i]-1)/2;
    cout << ans << endl;
}
    


