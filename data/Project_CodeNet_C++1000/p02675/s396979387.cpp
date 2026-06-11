#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int n;
  cin >> n;
  n %= 10;
  string ans;
  if(n== 2 || n == 4 || n == 5 || n== 7 || n == 9)ans = "hon";
  if(n==0 || n == 1 || n == 6 || n == 8) ans = "pon";
  if(n == 3) ans = "bon";
  cout << ans << endl;
}