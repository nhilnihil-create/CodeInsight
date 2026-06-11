#include<bits/stdc++.h>

using namespace std;

using ll = long long;


int main(){
  ll A, B, K;
  cin >> A >> B >> K;
  
  if(A>=K){
    cout << A-K << " " << B << endl; 
    return 0;
  }
  
  if(A<K){
    K = K-A;
    
    if(B<=K){
      cout << 0 << " " << 0 << endl;
    }else{
      cout << 0 << " " << B-K << endl;
    }
  }
  
  return 0;
}