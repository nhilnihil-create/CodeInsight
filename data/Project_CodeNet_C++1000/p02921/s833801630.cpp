#include <bits/stdc++.h>
using namespace std;
int main() {
  string A, B;
  int ans = 0;
  cin >> A >> B;
  for(int i = 0; i < 3; i++) { 
    if(A.at(i) == B.at(i)) {
      ans++;
    }
  }
  cout << ans << endl;
}
