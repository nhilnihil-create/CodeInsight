#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (n % 2 == 0){
    cout << 0.500000000 << endl;
  }
  else{
    double m = n/2 + 1;
    cout << fixed << setprecision(10);
    cout << m/n << endl;
  }
}