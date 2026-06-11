#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;

/*
10^n - 8^n
*/

ll powe(ll x, ll y){
    //xのy乗をMODで割った余り
    ll tmp=1;
    rep(i,y){
        tmp = (tmp * x)%MOD;
        while(tmp<0) tmp+MOD;
    }
    return tmp;
}

void solve(){

    ll n;
    cin >> n;
    ll t1,t2,t3;
    t1 = powe(10,n);
    t2 = powe(8,n);
    t3 = powe(9,n);
    ll ans = (((t1 + MOD*MOD - 2*t3)%MOD + t2)%MOD);
    while(ans<0) ans+MOD;
    cout << ans << endl;
    
    //cout << t1 << endl;
    //cout << t2 << endl;
    //cout << t3 << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
