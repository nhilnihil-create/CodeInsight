#include <bits/stdc++.h>
using namespace std;

int main(){
  for(int n, p; cin >> n >> p && (n|p); ) {
    int q = p;
    vector<int> a(n, 0);
    for(int k = 0; ; k = (k + 1) % n) {
      if(p) {
        a[k] += 1;
        p -= 1;
        if(a[k] == q) {
          cout << k << endl;
          break;
        }
      } else {
        p += a[k];
        a[k] = 0;
      }
    }
  }
  return 0;
}