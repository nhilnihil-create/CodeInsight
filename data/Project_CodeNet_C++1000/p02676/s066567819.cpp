#include <bits/stdc++.h>
using namespace std;

int main() {
  int K;
  string S,T;
  cin>>K>>S;
  if(S.size()<=K){
    cout << S << endl;
  }
  else{
    
    for(int i=0;i<K;i++){
      T += S[i];
    }
    
    cout << T << "..." << endl;
  }
      
  
}
