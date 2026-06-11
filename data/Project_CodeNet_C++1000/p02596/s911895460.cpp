#include <iostream>
using namespace std;

int main() {
  int k;
  int a[1000001];
  cin >> k;
  
  a[0] = 7 % k;
  for (int i = 1; i <= k; i++) {
    a[i] = ((a[i-1] * 10) % k + 7) % k; 
  }
  for (int i = 1; i <= k; i++) {
    if (a[i-1] == 0) {
      cout << i;
      return 0;
    }
  }
  cout << "-1";
}