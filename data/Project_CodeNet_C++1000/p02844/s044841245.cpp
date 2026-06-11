#include <bits/stdc++.h>
using namespace std;


int number(char c) {
  int num = 0;
  num = (int)(c - '0');
  return num;
}

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    a[i] = number(s[i]);
  }
  int ans = 0;
  for(int i = 0; i <= 999; i++) {
    int tmp[3] = {i / 100, (i % 100) / 10, i % 10};
    int j = 0;
    for(int k = 0; k < 3; k++) {
      while(j < n && tmp[k] != a[j]) {
        j++;
      }
      if(k < 2) {
        j++;
      }
    }
    if(j < n) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}