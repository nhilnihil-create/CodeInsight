#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int count = 0;
  for(int i=2; i<n; i++) {
    if(s[i]=='C' && s[i-1]=='B' && s[i-2]=='A') count++;
  }
  cout << count << endl;
  return 0;
}