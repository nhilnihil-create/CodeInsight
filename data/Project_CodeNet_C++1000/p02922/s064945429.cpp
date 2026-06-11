#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  
  int outlet = 1, ans = 0;
  while (outlet < B) {
    outlet += (A-1);
    ans++;
  }
  cout << ans << endl;
}