#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  cin >> N;
  string ans;
  if (N % 10 == 3) ans = "bon";
  else if (N % 10 == 0 || N % 10 == 1 || N % 10 == 6 || N % 10 == 8) ans = "pon";
  else ans = "hon";  
  cout << ans << endl;
}