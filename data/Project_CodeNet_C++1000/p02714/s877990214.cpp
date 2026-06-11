#include <iostream>
#include <string>

using namespace std;

int main() {
  int N;
  string s;
  cin >> N;
  cin >> s;
  
  int nr = 0, ng = 0, nb = 0;
  for (int i = 0; i < N; ++i) {
    switch (s[i]) {
      case 'R':
        nr++;
        break;
      case 'G':
        ng++;
        break;
      case 'B':
        nb++;
        break;
    }
  }
  
  long ans = (long)nr * ng * nb;
  long cnt = 0;
  for (int d = 1; d <= N / 2; ++d) {
    for (int i = 0; i + 2 * d < N; ++i) {
      int j = i + d;
      int k = i + 2 * d;
      if (s[i] != s[j] &&
          s[j] != s[k] &&
          s[k] != s[i]) {
        cnt++;
      }
    }
  }
  cout << ans - cnt << endl;
  
  return 0;
}