#include <iostream>
using namespace std;

int main() {
  unsigned long n, red = 0, count = 0;
  string c;
  cin >> n >> c;
  
  // 最後の赤を最初の白と交換していく
  // 赤を数える
  for (unsigned long i = 0; i < n; i++) if (c[i] == 'R') red++;
  // 赤の数分の左側のもののうち白の数を数える
  // その白を赤と交換すればよい
  for (unsigned long i = 0; i < red; i++) if (c[i] == 'W') count++;
  
  cout << count;
  
  return 0;
}