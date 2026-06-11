#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
using ll = long long;
 
int main() {
  string S, T;
  cin >> S >> T;
  int k = S.size();
  int ans = 0;
  rep(i, k) if(S.at(i) != T.at(i)) ans++;
  cout << ans << endl;
  return 0;
}