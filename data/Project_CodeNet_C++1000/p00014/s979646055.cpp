#include <bits/stdc++.h>
using namespace std;

int main() {
  int d;
  while( cin >> d ) {
    int result = 0;
    for ( int i = 1; d*i <= 600-d; i++ ) {
      result += (i*d)*(i*d)*d;
    }
    cout << result  << endl;
  }
  return 0;
}