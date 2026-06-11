#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  string s;
  cin >> n;
  int m = n;
  int count = 0;
  for(int i=0; i<m; i++) {
    s = to_string(n);
    if(s.size()%2 == 1) count++;
    n--;
  }
  cout << count << endl;
  return 0;
}