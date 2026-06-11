#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int j = 0; j < n; j++) cin >> a[j];
  
  for (int j = 0; j < k; j++) {
  	vector<int> b(n+1, 0);
 	for (int i = 0; i < n; i++) {
      int l = max(0, i - a[i]);
      int r = min(n, i + a[i]+1);
   	  b[l]++;
      b[r]--;
    }
    for (int i = 1; i < n; i++) b[i] += b[i-1];
    b.pop_back();
    if (a == b) break;
    a = b;
  }
  
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << endl;
}