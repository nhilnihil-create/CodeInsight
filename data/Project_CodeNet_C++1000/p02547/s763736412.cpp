#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    int d1, d2;
    cin >> d1 >> d2;
    if (d1 == d2) cnt++;
    else cnt = 0;
    if (cnt == 3) {
      puts("Yes");
      return 0;
    }
  }
  
  puts("No");
  return 0;
}
