#include<bits/stdc++.h>
using namespace std;
const int64_t mod=1000000007;
int64_t powermod(int k,int d){
  int64_t m=1;
  for(int i=0;i<k;i++){
    m=m*d%mod;
  }
  return m;
}
int main(){
  int n;
  cin >> n;
  int64_t ans=powermod(n,10)-powermod(n,9)-powermod(n,9)+powermod(n,8);
  ans%=mod;
  ans=(ans+mod)%mod;
  cout << ans << endl;
}