#include<iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  int x;
  
  x = N % 100;
  x %= 10;
  
  if(x == 3){
    cout << "bon" << endl;
  }else if (x == 0 || x == 1 || x == 6 || x == 8){
    cout << "pon" << endl;
  }else{
    cout << "hon" << endl;
  }
  
  return 0;
}
  
  