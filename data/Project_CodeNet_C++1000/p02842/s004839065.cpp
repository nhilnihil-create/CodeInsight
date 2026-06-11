#include <iostream>
#include <cmath>
using namespace std;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  long long N, _X; 
  double X;  
  cin >> N;
  
  X = ((double)N / 108) * 100; 
  _X = (N*100/108); 
  if ( X - _X > 0) {
  X = X - (X - _X) + 1; 
  } else {
    X = X - (X - _X); 
  }
  if ( floor(X * 1.08) == N) {
    cout << X; 
  } else {
    cout << ":("; 
  }
  
}