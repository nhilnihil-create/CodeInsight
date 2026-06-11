#include <bits/stdc++.h>
using namespace std;

int main(){
  const int Amax= 1e9;
  int N,K,S;
  cin >> N >> K >> S;

  if(S < Amax){
    for(int i=0; i<K; i++){
      cout << S <<" ";
    }
    for(int i=K; i<N; i++){
      cout << Amax <<" ";
    }
  }
  else{
    for(int i=0; i<K; i++){
      cout << S <<" ";
    }
    for(int i=K; i<N; i++){
      cout << 1 <<" ";
    }
  }
}