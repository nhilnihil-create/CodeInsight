#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> d1(n), d2(n);
  for(int i = 0; i < n; i++) {
    cin >> d1.at(i) >> d2.at(i);
  }
  vector<bool> d(n, 0);
  for(int i = 0; i < n; i++) {
    if(d1.at(i) == d2.at(i)) d.at(i) = 1;
  }
  bool x = 0;
  int c = 0;
  for(int i = 0; i < n; i++) {
    if(d.at(i) == 1) {
      c++;
      if(c == 3) {
        x = 1;
        break;
      }
    }
    else c = 0;
  }
  if(x) cout << "Yes" << endl;
  else cout << "No" << endl;
}