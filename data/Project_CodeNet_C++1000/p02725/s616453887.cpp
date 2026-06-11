#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  //string S;
  
  ll N, K;
  
  cin >> K >> N;
  vector<ll> A(N);
  for(int i=0; i<N; i++) cin >> A[i];
  
  vector<ll> B(N);
  for(int i=0; i<N; i++){
    if(i!=N-1) B[i] = abs(A[i+1] - A[i]);
    else{
      if(A[0]<K/2 && A[i]>K/2){
        A[i] = K-A[i];
        B[i] = A[i]+A[0];
      }
      else B[i] = abs(A[i]-A[0]);
    }
  }
  
  //for(int i=0; i<N; i++) cout << B[i] << endl;
  
  sort(B.begin(), B.end());
  ll sum = accumulate(B.begin(), B.end(), 0.0)-B[N-1];
  
  cout << sum << endl;

  return 0;
}