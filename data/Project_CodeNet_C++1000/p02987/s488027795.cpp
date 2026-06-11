#include <iostream>
using namespace std;
 
char S[4];
 
int main(){
  cin >> S;
  if(S[0] == S[1] && S[2] == S[3] && S[0] != S[2]){
    cout << "Yes";
  }
  else if(S[0] == S[2] && S[1] == S[3] && S[0] != S[1]){
    cout << "Yes";
  }
  else if(S[0] == S[3] && S[2] == S[1] && S[0] != S[1]){
    cout << "Yes";
  }
  else{
    cout << "No";
  }
}