#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
  ll N;
  cin >> N;
  vector<ll> A(N+1), B(N);
  for(int i=0; i<=N; i++) cin >> A[i];
  for(int i=0; i<N; i++) cin >> B[i];
  
  ll ans = 0;
  
  for(int i=0; i<N; i++){
    if(A[i]>=B[i]){
      A[i] -= B[i];
      ans += B[i];
    }else{
      B[i] -= A[i];
      ans += A[i];
      A[i] = 0;
      
      if(A[i+1]>=B[i]){
        A[i+1] -= B[i];
        ans += B[i];
      }else{
        B[i] -= A[i+1];
        ans += A[i+1];
        A[i+1] = 0;
      }
    }
  }
  
  cout << ans << endl;
  
  
  return 0;
}