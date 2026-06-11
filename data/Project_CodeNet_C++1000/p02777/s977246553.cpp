#include <iostream>
using namespace std;
 
int A;
int B;
string S;
string T;
string U;
 
int main(){
  cin >> S >> T >> A >> B >> U;
  if(S == U) A--;
  if(T == U) B--;
  cout << A << " " << B;
}