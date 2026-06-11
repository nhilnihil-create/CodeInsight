#include <bits/stdc++.h>
using namespace std;

int main() {
  long long a,b,c;
  cin >> c >> a >> b;
  long long  x = c / (a + b);
  long long y = c % (a + b);
  if (y > a) {
    cout << (a * x) + a <<endl;
  }
  else if (y <= a){
    cout << (a * x) + y <<endl;
  }

}
