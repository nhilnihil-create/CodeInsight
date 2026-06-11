#include <iostream>
using namespace std;
            
int main() {
  int n;
  cin >> n;

  int i, tmp, min, max;
  long long total;
  for (i = 0; i < n; i++) {
    cin >> tmp;
    if (i == 0) {
      min = tmp;
      max = tmp;
      total = tmp;
    } else {
      if (tmp < min) {
        min = tmp;
      } else if (tmp > max) {
        max = tmp;
      }
      total += tmp;
    }
  }
  cout << min << " " << max << " " << total << endl;
  return 0;
}