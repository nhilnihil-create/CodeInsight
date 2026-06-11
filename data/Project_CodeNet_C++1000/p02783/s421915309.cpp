#include <bits/stdc++.h>
using namespace std;
int main() {
  int H,A,ans=0; cin >> H >> A;
  while(H>0) {
    H -= A;
    ans++;
  }
  cout << ans << endl;
}