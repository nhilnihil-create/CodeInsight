#include<bits/stdc++.h>
using namespace std;

int main () {
  int n, m, ans = 0;
  cin >> n >> m;
  
  if (n != 0 || n != 1) {
    ans += n*(n-1)/2;
  }
  if (m != 0 || m != 1) {
    ans += m*(m-1)/2;
  }
  cout << ans << endl;
}