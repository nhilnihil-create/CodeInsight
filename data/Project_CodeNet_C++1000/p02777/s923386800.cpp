#include <bits/stdc++.h>
using namespace std;

int main () {
  string S, T;
  int s, t;
  string A;
  cin >> S >> T >> s >> t >> A;

  if (S == A) {
    s --;
  }
  else if (T == A) {
    t--;
  }
  cout << s << " " << t << endl;
}
