#include <bits/stdc++.h>
using namespace std;


int main(){
  int64_t N,K,S;
  cin >> N >> K >> S;
  for(int64_t i=0;i<K;i++){
    cout << S << " ";
  }
  for(int64_t i=K;i<N;i++){
    if(S==1000000000){
      cout << S-1 << " ";
    }else{
      cout << S+1 << " ";
    }
    
  }
  cout << endl;
}
