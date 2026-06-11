#include <iostream>
#include <cmath>
using namespace std;
int main(){
  double n;
  cin >> n;
  cout << ceil(n/1000)*1000-n << "\n";
  return 0;
}