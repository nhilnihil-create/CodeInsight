#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

int main(){
  ll a, b, c;
  cin >> a >> b >> c;
  
  ll d = c - a - b;
  string result = (d > 0 && d * d > 4 * a * b)? "Yes" : "No";
  cout << result;
  return 0;
}