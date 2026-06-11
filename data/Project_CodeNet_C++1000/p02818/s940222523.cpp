#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  long a, b, k;
  cin >> a >> b >> k;
  if(a < k) {
    b = max(b-(k-a), 0L);
    a = 0;
  } else {
    a = a - k;
  }
  cout << a << " " << b << endl;
  return 0;
}
