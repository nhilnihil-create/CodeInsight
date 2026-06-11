#include<iostream>
using namespace std;
int main(){
  int a;
  cin >> a;
  a = a % 10;
  if(a == 3){
    cout << "bon\n";
  }
  else if(a == 0 || a == 1 || a == 6 || a == 8){
    cout << "pon\n";
  }
  else{
    cout << "hon\n";
  }
}