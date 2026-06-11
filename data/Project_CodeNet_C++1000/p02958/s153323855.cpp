#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> l(n+1);
  int diff = 0;
  for(int i=1; i<=n; i++) {
    cin >> l[i];
    if(i != l[i]) {
      diff++;
    }
  }
  if(diff <= 2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}