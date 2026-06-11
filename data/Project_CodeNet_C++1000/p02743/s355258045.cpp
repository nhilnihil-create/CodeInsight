#include <bits/stdc++.h>
using namespace std;

int main() {
  long double a = 0, b = 0, c = 0;
  cin >> a >> b >> c;

  if(a + b - c + 2 * sqrt(a*b) < 0){
    cout << "Yes" << endl;
  }
  
  else{
    cout << "No" << endl;
  }
}
