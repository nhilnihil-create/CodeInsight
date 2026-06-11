#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int m,d;
  cin >> m >> d;

  int answer = 0;
  for (int i = 1; i <= m; i++) {
    for (int day = 10; day <= d; day++) {
      int d1 = day % 10;
      int d2 = day / 10;
      if(d1 * d2 == i && 2 <= d1 && 2 <= d2) answer++;
    }
  }
  cout << answer << endl;
  return 0;
}