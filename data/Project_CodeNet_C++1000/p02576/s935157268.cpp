#include <iostream>
#include <cmath>
using namespace std;

long long time(double n, int x, int t){
  return ceil(n/x)*t;
}

int main(){
  double n;
  long long x, t;
  cin >> n >> x >> t;
  cout << time(n,x,t);
}
