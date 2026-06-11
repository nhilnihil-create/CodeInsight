#include <iostream>
using namespace std;

char S[4];

int main(){
  cin >> S;
  if(S[0] == S[1] || S[1] == S[2] || S[2] == S[3]){
    cout << "Bad";
  }
  else{
    cout << "Good";
  }
}