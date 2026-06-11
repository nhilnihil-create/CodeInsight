#include <iostream>
using namespace std;

int main() {
  long n;
  cin >> n;
  long long a[n];
  for (long i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      cout << 0;
      return 0;
    }
  }
  
  long long result = 1;
  for (long i = 0; i < n; i++) {
    if (a[i] > 1000000000000000000/result) {
      result = -1;
      break;
    }
    result *= a[i];
  }
  
  cout << result;
  
  return 0;
}