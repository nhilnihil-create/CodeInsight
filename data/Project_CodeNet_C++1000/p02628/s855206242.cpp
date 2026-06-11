#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  unsigned int n, k, total = 0;
  cin >> n >> k;
  unsigned int p[n];
  for (unsigned int i = 0; i < n; i++) {
    cin >> p[i];
  }
  
  sort(p, p + n);
  
  for (unsigned int i = 0; i < k; i++) {
    total += p[i];
  }
  
  cout << total;
  
  return 0;
}