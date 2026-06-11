#include <iostream>
#include <cmath>
using namespace std;
int main(){
  double n,d;
  cin >> n >> d;
  cout << ceil(n/(2*d+1)) << "\n";
  return 0;
}