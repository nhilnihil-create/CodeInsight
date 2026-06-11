#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll; //10^19 < 9223372036854775807
typedef unsigned long long ull; //10^20 < 18446744073709551615

int main(){
  ll N, K; cin>>N>>K;
  ll ans;
  
  ans=N%K;
  ans=min(ans,abs(ans-K));
  /*
  while(N>K/2){
    N=abs(N-K);
  }*/
  cout << ans;
}