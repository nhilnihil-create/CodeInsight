#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  int x = s.size();
  int count = 0;
  for (int i=0; i<x/2; i++) {
      if (s[i] != s[x-1-i]) count++;
  }
  cout << count << endl;
  return 0;
}