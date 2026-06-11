#include <iostream>
using namespace std;
double EPS = 1e-10;
int main(){
  long long A;
  double B;
  cin >> A >> B;
  long long C = max(B * 100 + EPS, B * 100);
  cout << A * C / 100 << endl;
}