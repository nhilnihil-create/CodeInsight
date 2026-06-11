#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n, a;
  cin >> n;
  for(int i=0; i<n; i++) {
    cin >> a;
    if(a%2 == 0) {
      if(a%3 != 0) {
        if(a%5 != 0) {
          cout << "DENIED" << endl;
          return 0;
        }
      }
    }
  }
  cout << "APPROVED" << endl;
  return 0;
}