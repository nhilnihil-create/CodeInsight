#include <iostream>

using namespace std;

int main(void) {
  int n, x;
  while(cin >> n >> x && (n != 0 || x != 0)) {
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= n; j++) {
        for(int k = 1; k <= n; k++) {
          if(i < j && j < k && i + j + k == x) {
            cnt++;
          }
        }
      }
    }
    cout << cnt << endl;
  }
}