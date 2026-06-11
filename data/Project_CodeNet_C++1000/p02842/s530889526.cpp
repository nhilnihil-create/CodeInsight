#include <iostream>
using namespace std;

string getResult(const int taxPrice){
  for(int i = (int) (taxPrice / 1.08); ; i++){
    int compPrice = (int) (i * 1.08);
    if(compPrice == taxPrice) return to_string(i);
    if(compPrice > taxPrice) break;
  }
  return ":(";
}

int main(){
  int N;
  cin >> N;

  string result = getResult(N);
  cout << result;
  return 0;
}