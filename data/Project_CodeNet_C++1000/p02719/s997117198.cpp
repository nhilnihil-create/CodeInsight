#include <iostream>

using namespace std;

int main() {

  long long n, m, k = 1000000000000000001;
  cin >> n >> m;
  n = n % m;
  for(int i = 1;i <= 4;i++){
    k = min(n, k);
    n = abs(n - m);
  }
  k = min(n, k);
  cout << k;
  return 0;
}
