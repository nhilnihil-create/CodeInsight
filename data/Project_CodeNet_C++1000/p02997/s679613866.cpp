#include <iostream>

using namespace std;

int n, k;

int main()
{
  cin >> n >> k;
  
  int x = (n-1)*(n-2)/2 - k;
  
  if (x < 0) {
    cout << -1 << endl;
    return 0;
  }
  
  cout << (n-1) + x << endl;
  
  for (int i = 2; i <= n; i++) {
    cout << 1 << " " << i << endl;
  }
  
  for (int i = 2; i <= n-1; i++) {
    for (int j = i+1; j <= n; j++) {
      if (x == 0) {
        return 0;
      }
      cout << i << " " << j << endl;
      x--;
    }
  }
}