#include <bits/stdc++.h>
using namespace std;

int main(){
  int A,B,C,K;
  cin >> A >> B >> C >> K;
  for(int i=0;i<K;i++){
    if(B<=A){
      B*=2;
    }else if(C<=B){
      C*=2;
    }else{
      cout << "Yes" << endl;
      return 0;
    }
  }
  if((B>A)&&(C>B)){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
  return 0;
}
