#include <iostream>
#include <string>

using namespace std;

int main() {

  string str;
  cin >> str;
  if("MON" == str){
    cout << 6;
  }if("TUE" == str){
    cout << 5;
  }if("WED" == str){
    cout << 4;
  }if("THU" == str){
    cout << 3;
  }if("FRI" == str){
    cout << 2;
  }if("SAT" == str){
    cout << 1;
  }if("SUN" == str){
    cout << 7;
  }

  return 0;
}
