#include <iostream>
using namespace std;

int getResult(const int total){
  for(int i = 1; 100 * i <= total; i++){
    if(total <= 105 * i) return 1;
  }
  return 0;  
}

int main(){
  int X;
  cin >> X;

  int result = getResult(X);
  cout << result;
  return 0;
}