#include <bits/stdc++.h>

using namespace std;

typedef int64_t i64;

#define MAT_SIZE 121

int main() {
  i64 X;
  cin >> X;
  vector<i64> M(MAT_SIZE);
  for (i64 i = 0; i < M.size(); i++) {
    M[i] = i*i*i*i*i;
  }
  for (i64 a = 0; a < M.size()-1; a++) {
    for (i64 b = a+1; b < M.size(); b++) {
      i64 s[4] = {
         M[a] - M[b],
         M[a] + M[b],
        -M[a] - M[b],
        -M[a] + M[b]
      };
      if (s[0] == X) {
        cout << a << ' ' << b << endl; return 0;
      }
      if (s[1] == X) {
        cout << b << ' ' << -a << endl; return 0;
      }
      if (s[2] == X) {
        cout << -a << ' ' << b << endl; return 0;
      }
      if (s[3] == X) {
        cout << b << ' ' << a << endl; return 0;
      }
    }
  }
  return 0;
}
