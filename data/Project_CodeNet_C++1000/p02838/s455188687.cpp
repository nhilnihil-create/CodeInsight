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
    cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    rep(i,n){
        cin >> a[i];
    }
    rep(i,60){
        ll x = 0;
        rep(j,n){
            if(a[j]>>i & 1) x++;
        }
        ll ans = x*(n-x)%mod;
        rep(j,i){
            ans = ans*2 % mod;
        }
        sum += ans;
        sum %= mod;
    }
    cout << sum << endl;
    cout << endl;
    return 0;
}
