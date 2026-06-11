#include<iostream>
using namespace std;

int main(){
  int a,b,d,r;
  double f;

  cin >> a >> b;
  f = 1.000 * a / b;
  cout << a / b << " " << a % b << " " << fixed << f << endl;

  return 0;
}