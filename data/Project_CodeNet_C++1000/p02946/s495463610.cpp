#include<bits/stdc++.h>
using namespace std;

signed main() {
  int k,x;
  cin >> k >> x;
  int l = max(x-(k-1), -1000000);
  int r = min(x+(k-1), 1000000);
  for(int i=l; i<=r; i++) {
    cout << i << (i==r ? "\n" : " ");
  }
}
