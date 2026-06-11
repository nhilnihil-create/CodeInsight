#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;


int main(){
  int a, b, c;
  cin >> a >> b;
  cout << a / b << endl;
  cout << a % b << endl;
  cout << fixed << setprecision(10)<< (double)a / b << endl;
  return 0;
}