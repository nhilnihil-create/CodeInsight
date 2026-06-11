#include <iostream>
using namespace std;
 
int main() {
  unsigned long H, W;
  cin >> H >> W;
  if(H == 1 || W == 1) {
    cout << 1 << endl;
    return 0;
  }
  cout << (H * W / 2) + ((H * W) % 2) << endl;
  return 0;
}
