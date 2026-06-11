#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  vector<int> n(x);
  for(int i=0; i<x; i++) {
    cin >> n[i];
  }
  vector<int> p(x);
  for(int i=0; i<x; i++) {
    cin >> p[i];
  }
  vector<int> a(x-1);
  for(int i=0; i<x-1; i++) {
    cin >> a[i];
  }
  int ans = 0;
  int num = 100;
  int t;
  for(int i=0; i<x; i++) {
    bool j = false;
    if(num == n[i]-1) {
      j = true;
      t = num-1;
    }
    num = n[i];
    int point = p[i];
    int add = a[i];
    ans += p[i];
    if(j) {
      ans += a[t];
    }
  }
  cout << ans << endl;
}