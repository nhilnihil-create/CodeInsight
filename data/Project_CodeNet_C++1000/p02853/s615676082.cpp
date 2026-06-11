#include<bits/stdc++.h>
using namespace std;

int main () {
  int a, b, ans;
  cin >> a >> b;
  
  for (int i = 1; i <= 3; i++) {
    if (a==i) {
      ans += 4-i;
    }
    if (b==i) {
      ans += 4-i;
    }
  }
  if (a==1 && b==1) {
    ans += 4;
  }
  cout << ans * 100000 << endl;
}