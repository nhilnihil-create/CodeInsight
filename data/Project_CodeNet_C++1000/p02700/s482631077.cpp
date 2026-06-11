#include <iostream>

using namespace std;

int main() {

  int n, a, b, c, d;
  cin >> a >> b >> c >> d;
  if(c / b  + (c % b != 0) <= a / d +  (a % d != 0)){
    cout << "Yes";
  }else{
    cout << "No";
  }
  return 0;
}
