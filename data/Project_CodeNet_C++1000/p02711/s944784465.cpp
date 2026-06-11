#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  bool ans = false;
  for(int i=0; i<3; i++) {
    if(N %10 ==7) ans = true;
    N/=10;
  }
  if(ans==true) cout << "Yes" << endl;
  else cout << "No" << endl;
}