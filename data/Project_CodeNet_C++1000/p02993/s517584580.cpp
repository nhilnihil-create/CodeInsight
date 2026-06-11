#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  bool A=true;
  cin >> S;
  for(int i=1;i<S.size();i++){
    if(S.at(i)==S.at(i-1)){
      cout << "Bad" << endl;
      A=false;
      break;
    }
  }
  if(A==true){
    cout << "Good" << endl;
  }
}
