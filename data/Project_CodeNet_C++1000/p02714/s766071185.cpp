#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  string s;
  cin >> n >> s;
  
  long long r = 0, g = 0, b = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') r++;
    else if (s[i] == 'G') g++;
    else if (s[i] == 'B') b++;
  }
  
  int cnt = 0;
  
  for (int i = 0; i <= n-3; i++) {
    for (int j = i+1; j <= n-2; j++) {
      int k = j + j-i;
      if (k >= n) break;
      if (s[i] != s[j] && s[i] != s[k] && s[j] != s[k]) cnt++;
    }
  }
  
  cout << r*g*b - cnt;
  
  return 0;
}