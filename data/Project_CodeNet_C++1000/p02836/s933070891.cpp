#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, ans = 0;
  string s;
  cin >> s;  
  N = s.size();
  
  for (int i = 0; i < N/2; i++) {
    if (s[i] != s[N-i-1]) ans += 1;
  }
  
  cout << ans << endl;;
}