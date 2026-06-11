#include<iostream>
using namespace std;

using ll = long long;

int main(){

  ll A;
  cin >> A;
  double B;
  cin >> B;

  int C = (B+0.005) *100;

  ll ans = A*C/100;

  cout << ans << endl;

  return 0;
}
