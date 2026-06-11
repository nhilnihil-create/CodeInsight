#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,K,S;
  cin >> N >> K >> S;
  for(int i=0;i<K;i++){
    cout << S ;
    if(i<N-1)
      cout << " ";
  }
  for(int i=K;i<N;i++){
    cout << (S==1000000000?1:S+1);
    if(i<N-1)
      cout << " ";
  }
  cout << endl;
  return 0;
}