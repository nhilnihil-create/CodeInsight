#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, q;
  cin >> n >> k >> q;
  
  int a;
  vector<int> b(n);
  for(int i=0; i<q; i++) {
    cin >> a;
    b[a-1]++;
  }
  
  for(int i=0; i<n; i++) {
    if(k-q+b[i]>0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  
  return 0;
}