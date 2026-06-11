#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B,C;
  cin >> A >> B >>C;
  int ans = C - A + B;
  if(ans > 0) cout << ans;
  else cout <<0;
}
