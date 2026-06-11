#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a.at(i);
  bool c = 1;
  for(int A : a) {
    if(A % 2 == 0) {
      if(A % 3 != 0 && A % 5 != 0) {
        c = 0;
        break;
      }
    }
  }
  if(c) cout << "APPROVED" << endl;
  else cout << "DENIED" << endl;
}