#include<bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ans = 1;
  while((ans * n) % 360 != 0) {
    ans++;
  }
  cout << ans << endl;
  return 0;
}
