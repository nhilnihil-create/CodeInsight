#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
  int n;
  cin >> n;
  cout << fixed << setprecision(10) << ceil(n/2.0)/n << endl;
  return 0;
}