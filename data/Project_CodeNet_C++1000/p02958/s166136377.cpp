#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  for(int i=0; i<n; i++) {
    b[i] = i+1;
  }
  
  int count = 0;
  for(int i=0; i<n; i++) {
    if(a[i] != b[i]) count++;
  }
  if(count == 0 || count == 2) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}