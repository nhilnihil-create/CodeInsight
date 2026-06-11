#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  long long n,k;
  cin >> n >> k;
  
  long long rem = 0;
  rem = n % k;

  cout << min(rem,abs(rem-k)) << endl;
  return 0;
}
