#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main () {
  long long N; cin >> N;
  bool j = false;
  long long count = 0;

  if (N > 0) {
    for (int i = 1; i <= N; ++i) {
      if (i == 1 || i == 100 || i == 10000) {
        j = true;
      } else if (i == 10 || i == 1000) {
        j = false;
      } else if (i == 100000) {
        break;
      }

      if (j == true) {
        count += 1;
      } else {
        continue;
      }
    }
  }

  cout << count << endl;

  return 0;
}