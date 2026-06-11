#include <iostream>
using namespace std;

int main(void) {
  int n, d;
  cin >> n >> d;
  
  int range = 2*d+1;
  
  cout << (n + range - 1)/range;
  
  return 0;
}