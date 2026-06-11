#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int p;
  for(int i=0; i<n; i++) {
    cin >> p;
    if(p%2 == 0) {
      if(!(p%3 == 0 || p%5 == 0)) {
        cout << "DENIED" << endl;
        return 0;
      }
    }
  }
  cout << "APPROVED" << endl;
}