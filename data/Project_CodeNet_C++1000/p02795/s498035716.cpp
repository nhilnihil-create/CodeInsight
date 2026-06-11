#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int h, w, n;
  cin >> h >> w >> n;
  
  int s;
  
  if (h > w) {
    if (n % h == 0) {
      cout << n / h << endl;
    } else {
      cout << n / h + 1 << endl;
    }
  } else {
    if (n % w== 0) {
      cout << n / w << endl;
    } else {
      cout << n / w + 1 << endl;
    }
  }
  
}
