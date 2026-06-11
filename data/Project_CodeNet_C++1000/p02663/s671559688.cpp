#include<bits/stdc++.h>
using namespace std;

int main () {
  int h1, m1, h2, m2, k;
  cin >> h1 >> m1 >> h2 >> m2 >> k;
  
  int a = h2*60+m2-h1*60-m1, ans;
  if (a == k) {
    ans = 0;
  }
  else {
    ans = a-k;
  }
  cout << ans << endl;
}