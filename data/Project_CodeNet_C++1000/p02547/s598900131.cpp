#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, a, b;
  cin >> n;
  int count = 0;
  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    if (a == b) count++;
    else {
      if (count >= 3) {
        cout << "Yes";
        return 0;
      }
      else {
        count = 0;
      }
    }
  }
  if (count >= 3) cout << "Yes";
  else cout << "No";

}