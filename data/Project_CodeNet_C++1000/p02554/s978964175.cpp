#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;
const int MOD = 1e9+7;

//xのn乗
ll mod_pow(ll x, ll n) {// O(log(n))
    ll res = 1;
    while (n > 0) {//繰り返し二乗法
        if (n & 1) res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}
 
int main() {
  ll n, ans=0;
  cin>>n;
  ans=(mod_pow(10,n)-2*mod_pow(9,n)%MOD+mod_pow(8,n))%MOD;
  if(ans<0){
    ans+=MOD;
  }
  cout<<ans<<endl;
}
