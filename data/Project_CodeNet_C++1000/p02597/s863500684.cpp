#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

int main(){
    int  n;
    string s;
    cin >> n >> s;
    ll ans = 0;
    ll w = 0, r = 0;
    rep(i,n){
        if(s[i] == 'R')r++;
        else w++;
    }
    rep(i,r){
        if(s[i] == 'W')ans++;
    }
    cout << ans << endl;
    return 0;
}
