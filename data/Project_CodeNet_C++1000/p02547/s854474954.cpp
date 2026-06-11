#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int a, b, cnt = 0;
  bool check = false;
  for(int i=0; i<n; i++) {
    cin >> a >> b;
    if(a==b) cnt++;
    else cnt = 0;
    if(cnt==3) {
      check = true;
      break;
    }
  }
  
  if(check) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}