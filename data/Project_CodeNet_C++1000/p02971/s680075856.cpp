#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, M = 0, m = 0, s = 0;
  cin >> n;
  vector<int> v(n);
  for(int i = 0;i < n;i++) {
    cin >> v[i];
    if(M < v[i]) {
      m = M;
      M = v[i];
      s = 1;
    } else if(M == v[i]) {
      s++;
    } else if(m < v[i]) {
      m = v[i];
    }
  }
  if(s == 1) {
    for(int i = 0;i < n;i++) {
      if(v[i] == M) cout << m << endl;
      else cout << M << endl;
    }
  } else {
    for(int i = 0;i < n;i++) cout << M << endl;
  }
}