#include <iostream>
using namespace std;

bool check(int a, int b, int c) {
  if(a < b && b < c) return true;
  else return false;
}

int main() {
  int a, b, c, k; cin >> a >> b >> c >> k;
  if(check(a,b,c)) {
    cout << "Yes" << endl;
    return 0;
  }
  for(int i = 0; i < k; i++) {
    if(b <= a) b *= 2;
    else if(c <= b) c *= 2;
    if(check(a, b, c)) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
