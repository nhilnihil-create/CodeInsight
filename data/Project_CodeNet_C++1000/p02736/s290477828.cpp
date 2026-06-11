#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <bitset>
using namespace std;

int main() {
  int n;
  cin >> n;
  bool one = false;
  vector<int> a(n);
  for(int i=0;i<n;i++) {
    char c;
    cin >> c;
    a[i] = c - '1';
    if(a[i] == 1) one = true;
  }
  int ans = 0;
  for(int i=0;i<n;i++) {
    if(a[i] % 2 == 0) continue;
    else {
      bool even = false;
      bitset<32> x(n-1);
      bitset<32> y(i);
      for(int j=0;j<32;j++) {
        if(!x.test(j) && y.test(j)) {
          even = true;
          break;
        }
      }
      if(!even) ans ^= 1;
    }
  }
  if(ans == 1) {
    cout << 1 << endl;
    return 0;
  }
  if(one) {
    cout << 0 << endl;
    return 0;
  }
  for(int i=0;i<n;i++) {
    if(a[i] == 0) continue;
    a[i] /= 2;
    bool even = false;
    bitset<32> x(n-1);
    bitset<32> y(i);
    for(int j=0;j<32;j++) {
      if(!x.test(j) && y.test(j)) {
        even = true;
        break;
      }
    }
    if(!even) ans ^= 1;
  }
  cout << ans * 2 << endl;
  return 0;
}
