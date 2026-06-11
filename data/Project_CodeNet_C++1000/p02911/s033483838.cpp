#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  ll N, K, Q;
  
  cin >> N >> K >> Q;
  vector<ll> A(Q);
  for(int i=0; i<Q; i++) cin >> A[i];
  vector<ll> loss(N);
  for(int i=0; i<N; i++) loss[i] = Q;
  for(int i=0; i<Q; i++) loss[A[i]-1]--;
  
  for(int i=0; i<N; i++){
   if(K-loss[i]>0){
     cout << "Yes" << endl;
   } else{
     cout << "No" << endl;
   }
  }
  

  return 0;
}
