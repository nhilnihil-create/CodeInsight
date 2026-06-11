#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const ll MOD = 1000000007;
ll cnt =0,ans=0;
const int MAX = 510000;
long long fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理、これも呼ぶ

ll powmod(ll x,ll y){
     ll res = 1;
     for(ll i = 0;i<y;i++){
          res=res*x%MOD;
     }
     return res;
}
int main (){
     ll n;     cin >> n;
     ans = powmod(10,n) - 2*powmod(9,n) + powmod(8,n);
     ans %= MOD;
     ans = (ans+MOD)%MOD;
     cout << ans << endl; 
}