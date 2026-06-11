#include <bits/stdc++.h>
using namespace std;

bool find(int i, int j, int k, string s) {
  int now = 0;
  for (int idx = 0; idx < s.size(); idx++) {
    if (now == 0 && s[idx] == '0' + i) {
      now++;
      continue;
    }
    if (now == 1 && s[idx] == '0' + j) {
      now++;
      continue;
    }
    if (now == 2 && s[idx] == '0' + k) {
      now++;
      break;
    }
  }
  if (now == 3) {
    return true;
  } else {
    return false;
  }
}

int solve(int n, string s) {
  int ans = 0;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        if (find(i, j, k, s)) {
          ans++;
        }
      }
    }
  }
  return ans;
}
int main() {
  int n;
  string s;
  cin >> n >> s;
  cout << solve(n, s) << endl;
}
