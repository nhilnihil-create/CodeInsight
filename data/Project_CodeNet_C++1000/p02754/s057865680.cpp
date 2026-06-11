#include <iostream>

using namespace std;

int main() {

  unsigned long long a, b, c;
  cin >> a >> b >> c;
  if(a % (b + c) > b){
    cout << b * (a / (b + c)) + b;
  }else{
    cout << b * (a / (b + c)) + a % (b + c);
  }
  return 0;
}
