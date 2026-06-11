#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define per(i,n) for (int i=n-1; i>=0; --i)
#define all(a) a.begin(), a.end()
using namespace std;
using ll = long long;
using P  = pair<int,int>;
using vi = vector<int>;
using vv = vector<vi>;
const int mod = 1000000007;
//const int mod = 998244353;

int main(){
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    
    for(ll i=k; i<=n+1; i++){
        ans += (2*n -(i-1))*i/2;
        ans -= (i-1)*i /2;
        ans += 1;
        ans %= mod;
    }
    
    cout << ans << endl;
    
    return 0;
}