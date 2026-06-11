#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define All(a) (a).begin(),(a).end()

ll M=pow(10,9)+7;
ll powMod(ll n, ll k, ll p) {
//n^k mod p
  ll ans=1;
  while(k>0){
    if(k&1) ans=(ans*n)%p;
    k>>=1;
    n=(n*n)%p;
  }
  return ans;
}
void solve(){
  ll n,a,b,c,ans;
  cin >> n;
  
  a=powMod(10,n,M);
  b=powMod(9,n,M);
  c=powMod(8,n,M);
  ans=(a-2*b+c)%M;
  while(ans<0)ans+=M;
  //cout << ans <<endl;
  //ans=powMod(2,30,M);
  cout<<ans<<endl;
}
int main(){
  solve();
  return 0;
}