#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i += 2)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i += 2)
int main() {
  string A;
  cin >> A;
  int LOL = 0;
  rep(i, A.size()) {
    if(A.at(i) == 'L') {
      LOL++;
    }
  }
  rep2(i, 1, A.size()) {
    if(A.at(i) == 'R') {
      LOL++;
    }
  }
  if(LOL > 0) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
}
    
