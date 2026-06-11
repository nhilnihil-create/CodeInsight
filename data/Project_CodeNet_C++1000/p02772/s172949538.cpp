#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, p;
  cin >> N;
  string ans = "APPROVED";
  for (int i=0; i<N; i++) {
    cin >> p;
    if (p%2==0) {
      if (p%3 != 0 && p%5 != 0) {
        ans = "DENIED";
        break;
      }
    }
  }
  cout << ans << endl;
}