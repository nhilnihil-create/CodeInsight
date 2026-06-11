#define rep(i,n) for (int i=0;i<n;i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

 ll modpow(ll x,ll y){
    ll res=1;
    for(ll i=0;i<y;i++){
        res=res*x%mod;
    }
    return res;
}
 
int main(){
  
int n;
  cin >> n;
  ll ans = (modpow(10,n)-2*modpow(9,n)+modpow(8,n))%mod;
  if(ans<0)
    ans+=mod;
  
  cout << ans << endl;
  
  
}


