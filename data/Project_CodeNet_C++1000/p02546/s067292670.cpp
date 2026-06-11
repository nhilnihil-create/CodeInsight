#include <iostream>
using namespace std;

int main(void){
  string S;
  cin >> S;
  int len = S.length();
  
  if(S[len-1]=='s'){
    S += "es";
  }else{
    S += "s";
  }
  
  cout<< S << endl;
  return 0;
}