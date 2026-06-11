# include <iostream>
using namespace std;

int k, x;

int main() {
  cin >> k >> x;
  int cnt = 1;
  int start = x - k + 1;
  while (cnt < 2 * k) {
    if (cnt != 2 * k - 1) cout << start << " ";
    else cout << start << endl;
    
    cnt++; start++;
  }
  
  return 0;
}