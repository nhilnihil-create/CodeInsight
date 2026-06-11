#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll MOD = 1000000007;
ll inv = 500000004;

int main(){
  ll N,K;cin >> N >> K;
  vector<ll> A(N,0);
  for(int i=0;i<N;i++){
    cin >> A[i];
  }
  ll ans = 0;
  for(int i=0;i<N;i++){
    ll sum1=0,sum2=0;
    for(int j=0;j<i;j++){
      if(A[i]>A[j]){
        sum1 += 1;
      }
    }
    for(int j=i+1;j<N;j++){
      if(A[i]>A[j]){
        sum2 += 1;
      }
    }
    ll K1 = K*(K-1)%MOD*inv%MOD;
    ll K2 = K*(K+1)%MOD*inv%MOD;
    ans = (ans + sum1*K1%MOD)%MOD;
    ans = (ans + sum2*K2%MOD)%MOD;
  }
  cout << ans << endl;
}