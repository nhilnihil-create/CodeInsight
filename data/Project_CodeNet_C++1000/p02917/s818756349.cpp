#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
  ll N;
  cin >> N;
  
  vector<ll> B(N-1);
  for(int i=0; i<(N-1); i++) cin >> B[i];
  vector<ll> A(N);
  
  A[0] = B[0];
  A[1] = B[0];
  
  for(int i=1; i<(N-1); i++){
    A[i+1] = B[i];
    if(A[i]>B[i]) A[i] = B[i];
  }
  
  cout << accumulate(A.begin(), A.end(), 0) << endl;
  
  return 0;
}