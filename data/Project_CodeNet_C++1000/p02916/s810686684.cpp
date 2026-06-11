#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  vector<ll> C(N-1);
  
  for(int i=0; i<N; i++) cin >> A[i];
  for(int i=0; i<N; i++) cin >> B[i];
  for(int i=0; i<(N-1); i++) cin >> C[i];
  
  ll ans = 0;
  
  for(int i=0; i<N; i++){
    ans += B[A[i]-1];
    if(A[i]==(A[i+1]-1)){
      ans += C[A[i]-1];
    }
  
  }
  
  cout << ans << endl;
  
  
  return 0;
}