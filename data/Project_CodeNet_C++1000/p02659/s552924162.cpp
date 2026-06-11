#include <iostream>
using namespace std;

int main() {
  long long a;
  double b;
  cin >> a >> b;
  
  long long c = b*100 + 0.01;
  long long d = b*100;
  
  cout << (a*c)/100;
  
  return 0;
}