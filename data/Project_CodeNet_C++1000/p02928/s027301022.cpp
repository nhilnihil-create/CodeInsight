#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int INF = 2e9;
const ll MOD = 1e9+7;

int main(){
    ll n,k;
    cin >> n >> k;
    vector<int> b(n);
    rep(i,n) cin >> b[i];
    ll ans = 0;
    rep(i,n){
        ll a = b[i];
        ll l = 0;
        ll r = 0;
        for(int j = 0; j < n;j++){
            if(j < i && b[j] > a)l++;
            if(b[j] > a)r++;
        }
        ans += l * k % MOD;
        ans %= MOD;
        ans += k * (k-1) / 2 % MOD * r % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}