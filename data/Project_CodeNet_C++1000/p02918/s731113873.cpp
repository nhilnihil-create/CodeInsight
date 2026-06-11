#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, ans, maxi; cin >> n >> k; ans = maxi = --n;
  string s; cin >> s;
  while(n){ if (s[n-1] != s[n]) ans--;  n--;}
  cout << min(ans + 2*k, maxi) << endl;
}