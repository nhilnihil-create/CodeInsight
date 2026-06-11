#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[6] = {0,1,0,-1,1,-1};
const int vy[6] = {1,0,-1,0,1,1};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    string s;
    cin >> n >> s;
    ll r = 0,g = 0,b = 0;
    rep(i,n){
        if(s[i] == 'R') r++;
        else if(s[i] == 'G') g++;
        else b++;
    }
    ll ans = r*g*b;
    rep(i,n){
        for(ll j = i;j < n;++j){
            ll k = 2*j-i;
            if(k < 0 || k >= n) continue;
            if(i == j || i == k || j == k) continue;
            if(s[i] == s[j]) continue;
            if(s[i] == s[k]) continue;
            if(s[j] == s[k]) continue;
            ans--;
        }
    }
    cout << ans << endl;
    cout << endl;
    return 0;
}
