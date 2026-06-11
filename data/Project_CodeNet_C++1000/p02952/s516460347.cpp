#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  int A = 1;
  int ans = 0;
  while (A <= N) {
    if ((A%10 > 0 && A/10 == 0) || (A%1000 > 99 && A/1000 == 0) || (A%100000 > 9999 && A/1000000 == 0))
      ans++;
    A++;
  }
  cout << ans << endl;
}