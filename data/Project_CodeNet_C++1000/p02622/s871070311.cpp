#include <iostream>
#include <string>
using namespace std;

int main(){
  int score = 0;
  string S1;
  string S2;
  cin >> S1 >> S2;
  
  for (int i = 0; i < S1.length(); i++){
    if (S1[i] != S2[i]) score++;
  }
  
  cout << score;
  return 0;
}
