#include <iostream>
using namespace std;

int main(){
  int A, B;
  
  cin >> A >> B;
  
  for(int i = 0;i < 10000;i++){
    int a = i * 8 / 100;
    int b = i * 10 / 100;
    if(A == a && B == b){
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  
  return 0;
}