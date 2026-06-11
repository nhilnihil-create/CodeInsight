#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n >> s;
  if (n%2==0) {
    for(int i=0; i<n/2; i++) {
      if(s[i] != s[n/2+i]) {
        cout << "No" << endl;
        return 0;
      }
    }
    cout << "Yes" << endl;
    return 0;
  }
  else cout << "No" << endl;
  return 0;
}