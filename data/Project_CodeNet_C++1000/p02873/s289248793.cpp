#include<bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size() + 1;
  int count = 0;
  vector<int> a(n, 0);
  for(int i=0; i<n-1; i++) {
    if(s.at(i) == '<') {
      count++;
    } else {
      count = 0;
    }
    a.at(i+1) = count;
  }
  count = 0;
  for(int i=n-2; i>=0; i--) {
    if(s.at(i) == '>') {
      count++;
    } else {
      count = 0;
    }
    a.at(i) = max(a.at(i), count);
  }
  long long ans = 0;
  for(int i=0; i<n; i++) {
    ans += a.at(i);
  }
  cout << ans << endl;
}