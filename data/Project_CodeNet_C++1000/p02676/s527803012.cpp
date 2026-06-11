#include <bits/stdc++.h>
using namespace std;

int main(){
  int K,N=0;
  string S;
  cin >> K >> S;
  N += S.size();
  if(N<=K){
    cout << S << endl;
    return 0;
  }
  for(int i=0; i<K; i++){
    cout << S[i];
  }
  cout << "..." << endl;
}
