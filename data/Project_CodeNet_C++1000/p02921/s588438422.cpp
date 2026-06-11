#include <iostream>
using namespace std;
 
int total;
string S;
string T;
 
int main(){
  cin >> S >> T;
  total = 0;
  if(S[0] == T[0]){
    total++;
  }
  if(S[1] == T[1]){
    total++;
  }
  if(S[2] == T[2]){
    total++;
  }
  cout << total;
}