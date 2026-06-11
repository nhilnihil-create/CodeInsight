#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, m;
  cin >> S;
  int N = S.size();
  int count = 0;
  for (int i = 0; i < N; i++) {
    string f = S.substr(i,1);
    if (m == f) {
      m = S.substr(i,2);
      i += 1;
      if (i != N) count += 1;
    }
    else{
      m = f;
      count += 1;
    }
  }
  cout << count << endl;
}