#include <iostream>
using namespace std;

int main(){
  int n;
  cin >> n;
  double p = 1.0 - (n/2) / (double)n;
  cout << p << endl;
  
  return 0;
}