#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,l;
  cin >> n >> l;
  vector<int> t(n);
  for (int i = 0;i < n;i++){
    t[i] = l + i;
  }
  int e = t[0];
  
  for (int i = 1;i < n;i++){
    if (abs(e) >= abs(t[i])){
      e = t[i];
    }
  }
  int ans = 0;
  for (int i = 0;i < n;i++){
     ans += t[i];
  }
  
  cout << ans - e << endl;
}