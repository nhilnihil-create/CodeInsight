#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string s, ans = "No";
  cin >> N >> s;
  
  if (N%2 == 0) {
    for (int i = 0; i < N/2; i++) {
      if (s[i] != s[N/2+i]) break;
      if (s[i] == s[N/2+i] && i == N/2-1) ans = "Yes";
    }
  }
  
  cout << ans << endl;;
}