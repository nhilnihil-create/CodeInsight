#include<iostream>
using namespace std;
int main(){
  double a, b, s;
  int c;
  cin >> a;
  c = a;
  if(c % 2 == 1){
    b = c / 2 + 1;
  }
  else{
    b  = c / 2;
  }
  s = b / a;
  cout << s;
}