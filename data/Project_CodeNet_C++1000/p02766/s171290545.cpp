#include <iostream>

using namespace std;
int main(){
  long n, k;
  cin >> n >> k;
 
  long d = 1L, digi = 0L;
  while(d <= n) {
    digi++;
    d = d*k;
  }
  cout << digi << endl;
  return 0;
}
