#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, cnt = 0;
  cin >> n;
  string s;
  cin >> s;
  for(int i = 0; i < 1000; i++) {
    vector<int> v(3);
    v[0] = i % 10;
    v[1] = (i % 100) / 10;
    v[2] = i / 100;
    int idx = 0;
    for(int j = 0; j < n; j++) {
      if(s[j] - '0' == v[idx]) idx++;
      if(idx == 3) {
        cnt++;
        break;
      }
    }
  }
  cout << cnt;
}