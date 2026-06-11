#include<iostream>
using namespace std;

int main(){
  string S, T;
  cin >> S >> T;
  
  for (int i = 0; i < S.size(); i++){
    if (S[i] != T[i]){
      cout << "No" << endl;
      break;
    }
    if (i == S.size() - 1){
      cout << "Yes" << endl;
    }
  }
  return 0;
}